class House{
public:
	void Init(){
		this->BuildPart1();
		for (int i = 0; i < 4; i++)
			this->BuildPart2();

		bool flag = this->BuildPart3();

		if(flag)
			this->BuildPart4();

		this->BuildPart5();
	 
	}
	virtual ~House(){}
protected:
	virtual void BuildPart1() = 0;
	virtual void BuildPart2() = 0;
	virtual void BuildPart3() = 0;
	virtual void BuildPart4() = 0;
	virtual void BuildPart5() = 0;
};

//拆分构建过程和House具体类
class House{
 
 	friend class HouseBuilder;
}

class HouseBuilder{
public:
	HouseBuilder(House* phouse):pHouse(phouse){

	}	

/*
	void Init(){
		this->BuildPart1();
		for (int i = 0; i < 4; i++)
			this->BuildPart2();

		bool flag = this->BuildPart3();

		if(flag)
			this->BuildPart4();

		this->BuildPart5();
	 
	}
	*/
	House* getResult() {return pHouse;}
	virtual ~HouseBuilder(){}
protected:
	House *pHouse; 
	virtual void BuildPart1() = 0;
	virtual void BuildPart2() = 0;
	virtual void BuildPart3() = 0;
	virtual void BuildPart4() = 0;
	virtual void BuildPart5() = 0;
};

class StoneHouse: public House{
 
};

class StoneHouseBuilder: public HouseBuilder{
protected:
	virtual void BuildPart1(){
	 
	}
	virtual void BuildPart2(){
	 
	}
	virtual void BuildPart3(){
	 
	}
	virtual void BuildPart4(){
	 
	}
	virtual void BuildPart5(){
	 
	}
}


class HouseDirector{
public:
	HouseBuilder *pHouseBuilder;
	HouseDirector(HouseBuilder* pHouseBuilder){
	 	this->pHouseBuilder = pHouseBuilder;
	}

	House* Construct(){
		pHouseBuilder->BuildPart1();
		for (int i = 0; i < 4; i++)
			pHouseBuilder->BuildPart2();

		bool flag = pHouseBuilder->BuildPart3();

		if(flag)
			pHouseBuilder->BuildPart4();

		pHouseBuilder->BuildPart5();

		return pHouseBuilder->getResult();
	}
};

int main()
{
	//没有拆分的类
	House* pHouse = new StoneHouse(); 
	pHouse->Init();

	//拆分成builder后
	House *pStoneHouse = new StoneHouse();
	HouseBuilder *pHouseBuilder = new StoneHouseBuilder(pStoneHouse);
	HouseDirector *pHouseDirector = new HouseDirector(pHouseBuilder);
	pStoneHouse = pHouseDirector->Construct();
	
	return 0;
}
