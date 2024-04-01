#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;


// Абстрактный класс аппаратного устройства
class AbstractDevice abstract
{
protected:
	string producer;

public:
	string GetProducer()
	{
		return this->producer;
	}
	void SetProducer(string producer)
	{
		this->producer = producer;
	}
 // Метод создания клона объекта
	virtual AbstractDevice* Clone() abstract;
};





class Web : public AbstractDevice
{
	string color;
	string videoResolution;
public:
	string GetColor()
	{
		return this->color;
	}
	void SetColor(string color)
	{
		this->color = color;
	}






	string GetVideoResolution()
	{
		return this->videoResolution;
	}
	void SetVideoResolution(string videoResolution)
	{
		this->videoResolution = videoResolution;
	}



	AbstractDevice* Clone() override
	{
		Web* web = new Web;
		*web = *this;
		return web;
	}
};


class Mouse : public AbstractDevice
{
	string color;
	string submission;
	
public:
	string GetColor()
	{
		return this->color;
	}
	void SetColor(string color)
	{
		this->color = color;
	}




	string GetSubmission()
	{
		return this->submission;
	}
	void SetSubmission(string submission)
	{
		this->submission = submission;
	}





	AbstractDevice* Clone() override
	{
		Mouse* mouse = new Mouse;
		*mouse = *this;
		return mouse;
	}
};





class Box : public AbstractDevice
{
	string color;
public:
	string GetColor()
	{
		return this->color;
	}
	void SetColor(string color)
	{
		this->color = color;
	}
	AbstractDevice* Clone() override
	{
		Box * box = new Box;
		*box = *this;
		return box;
	}
};

class Memory : public AbstractDevice
{
	int volume;
	string type;
public:
	string GetType()
	{
		return this->type;
	}
	void SetType(string type)
	{
		this->type = type;
	}
	int GetVolume()
	{
		return this->volume;
	}
	void SetVolume(int volume)
	{
		this->volume = volume;
	}
	AbstractDevice* Clone() override
	{
		Memory * memory = new Memory;
		*memory = *this;
		return memory;
	}
};

class Hdd : public AbstractDevice
{
	int volume;
	string type;
public:
	string GetType()
	{
		return this->type;
	}
	void SetType(string type)
	{
		this->type = type;
	}
	int GetVolume()
	{
		return this->volume;
	}
	void SetVolume(int volume)
	{
		this->volume = volume;
	}
	AbstractDevice* Clone() override
	{
		Hdd * hdd = new Hdd;
		*hdd = *this;
		return hdd;
	}
};

class Processor : public AbstractDevice
{
	int corecount;
	double frequency;
public:
	double GetFrequency()
	{
		return this->frequency;
	}
	void SetFrequency(double frequency)
	{
		this->frequency = frequency;
	}
	int GetCoreCount()
	{
		return this->corecount;
	}
	void SetCoreCount(int corecount)
	{
		this->corecount = corecount;
	}
	AbstractDevice* Clone() override
	{
		Processor * processor = new Processor;
		*processor = *this;
		return processor;
	}
};

class VideoCard : public AbstractDevice
{
	int volume;
public:
	int GetVolume()
	{
		return this->volume;
	}
	void SetVolume(int volume)
	{
		this->volume = volume;
	}
	AbstractDevice* Clone() override
	{
		VideoCard * videocard = new VideoCard;
		*videocard = *this;
		return videocard;
	}
};

class Mainboard : public AbstractDevice
{
	double busfrequency;
	VideoCard* videocard;
public:
	double GetBusFrequency()
	{
		return this->busfrequency;
	}
	void SetBusFrequency(double busfrequency)
	{
		this->busfrequency = busfrequency;
	}
	VideoCard* GetVideoCard()
	{
		return this->videocard;
	}
	void SetVideoCard(VideoCard* videocard)
	{
		this->videocard = videocard;
	}
	AbstractDevice* Clone() override
	{
		Mainboard *newObj = new Mainboard;
		*newObj = *this;
		newObj->videocard = this->videocard != nullptr? (VideoCard*) this->videocard->Clone() : nullptr;
		return newObj;
	}
};

/*
 Прототип (Prototype) порождающий шаблон проектирования, который предназначен для создания объекта
 через клонирование другого объекта вместо создания посредством конструктора.
Паттерн используется чтобы:
-	избежать дополнительных усилий по созданию объекта стандартным путем (использование ключевого слова new,
	когда создается не только сам объект, но и вся иерархия предков объекта),
	когда это непозволительно дорого для приложения.
-	избежать наследования создателя объекта (object creator) в клиентском приложении, как это делает паттерн abstract factory.
*/

class Prototype abstract
{
public:
	 virtual Prototype* Clone() abstract;
};

class PersonalComputer: public Prototype
{
	Box* box;
	Mainboard* mainboard;
	Processor* processor;
	VideoCard* videocard;
	vector<Memory*> memories;
	vector<Hdd*> hdd;
public:
	Box* GetBox()
	{
		return this->box;
	}
	void SetBox(Box* box)
	{
		this->box = box;
	}
	Processor* GetProcessor()
	{
		return this->processor;
	}
	void SetProcessor(Processor* processor)
	{
		this->processor = processor;
	}
	Mainboard* GetMainboard()
	{
		return this->mainboard;
	}
	void SetMainboard(Mainboard* mainboard)
	{
		this->mainboard = mainboard;
	}
	VideoCard* GetVideoCard()
	{
		return this->videocard;
	}
	void SetVideoCard(VideoCard* videocard)
	{
		this->videocard = videocard;
	}
	vector<Memory*>& GetMemories()
	{
		return memories;
	}
	void AddMemory(Memory * m)
	{
		memories.push_back(m);
	}
	vector<Hdd*>& GetHdd()
	{
		return hdd;
	}
	void AddHdd(Hdd * hdd)
	{
		this->hdd.push_back(hdd);
	}
	Prototype* Clone() override//компютер сам себя клонирует тоже
	{
		PersonalComputer *pc = new PersonalComputer;//создали новый комп
		pc->box = this->box != nullptr ? (Box*)this->box->Clone(): nullptr;
		pc->mainboard = this->mainboard != nullptr ? (Mainboard*)this->mainboard->Clone(): nullptr;
		pc->processor = this->processor != nullptr ? (Processor*)this->processor->Clone() : nullptr;
		pc->videocard = this->videocard != nullptr ? (VideoCard*)this->videocard->Clone() : nullptr;
		for(Memory* m : this->memories)
		{
			if (m != nullptr)
			{
				pc->AddMemory((Memory*)m->Clone());
			}
		}
		for (Hdd* h : this->hdd)
		{
			if (h != nullptr)
			{
				pc->AddHdd((Hdd*)h->Clone());
			}
		}		
		return pc;
	}
};











class Mobile : public Prototype
{
	Web* web;


	Box* box;
	Mainboard* mainboard;
	Processor* processor;
	vector<Memory*> memories;
	

public:
	Box* GetBox()
	{
		return this->box;
	}
	void SetBox(Box* box)
	{
		this->box = box;
	}
	Processor* GetProcessor()
	{
		return this->processor;
	}
	void SetProcessor(Processor* processor)
	{
		this->processor = processor;
	}
	Mainboard* GetMainboard()
	{
		return this->mainboard;
	}
	void SetMainboard(Mainboard* mainboard)
	{
		this->mainboard = mainboard;
	}



	vector<Memory*>& GetMemories()
	{
		return memories;
	}
	void AddMemory(Memory* m)
	{
		memories.push_back(m);
	}



	Web* GetWeb()
	{
		return this->web;
	}
	void SetWeb(Web* web)
	{
		this->web = web;
	}







	Prototype* Clone() override//компютер сам себя клонирует тоже
	{
		Mobile* mob = new Mobile;//создали новый комп
		mob->box = this->box != nullptr ? (Box*)this->box->Clone() : nullptr;
		mob->mainboard = this->mainboard != nullptr ? (Mainboard*)this->mainboard->Clone() : nullptr;
		mob->processor = this->processor != nullptr ? (Processor*)this->processor->Clone() : nullptr;
		mob->web = this->web != nullptr ? (Web*)this->web->Clone() : nullptr;
		for (Memory* m : this->memories)
		{
			if (m != nullptr)
			{
				mob->AddMemory((Memory*)m->Clone());
			}
		}
	

		return mob;
	}
};





class Laptop : public Prototype
{
	
	Web* web;
	Mouse* mouse;

	Box* box;
	Mainboard* mainboard;
	Processor* processor;
	VideoCard* videocard;
	vector<Memory*> memories;
	vector<Hdd*> hdd;
	


public:
	Box* GetBox()
	{
		return this->box;
	}
	void SetBox(Box* box)
	{
		this->box = box;
	}
	Processor* GetProcessor()
	{
		return this->processor;
	}
	void SetProcessor(Processor* processor)
	{
		this->processor = processor;
	}
	Mainboard* GetMainboard()
	{
		return this->mainboard;
	}
	void SetMainboard(Mainboard* mainboard)
	{
		this->mainboard = mainboard;
	}
	VideoCard* GetVideoCard()
	{
		return this->videocard;
	}
	void SetVideoCard(VideoCard* videocard)
	{
		this->videocard = videocard;
	}
	vector<Memory*>& GetMemories()
	{
		return memories;
	}
	void AddMemory(Memory* m)
	{
		memories.push_back(m);
	}
	vector<Hdd*>& GetHdd()
	{
		return hdd;
	}
	void AddHdd(Hdd* hdd)
	{
		this->hdd.push_back(hdd);
	}



	Web* GetWeb()
	{
		return this->web;
	}
	void SetWeb(Web* web)
	{
		this->web = web;
	}




	Mouse* GetMouse()
	{
		return this->mouse;
	}
	void SetMouse(Mouse* mouse)
	{
		this->mouse = mouse;
	}










	Prototype* Clone() override//компютер сам себя клонирует тоже
	{
		Laptop* laptop = new Laptop;//создали новый комп
		laptop->box = this->box!= nullptr ? (Box*)this->box->Clone() : nullptr;


		laptop->mainboard = this->mainboard != nullptr ? (Mainboard*)this->mainboard->Clone() : nullptr;
		laptop->processor = this->processor != nullptr ? (Processor*)this->processor->Clone() : nullptr;
		laptop->videocard = this->videocard != nullptr ? (VideoCard*)this->videocard->Clone() : nullptr;

		laptop->web = this->web != nullptr ? (Web*)this->web->Clone() : nullptr;
		laptop->mouse = this->mouse != nullptr ? (Mouse*)this->mouse->Clone() : nullptr;
		for (Memory* m : this->memories)
		{
			if (m != nullptr)
			{
				laptop->AddMemory((Memory*)m->Clone());
			}
		}
		for (Hdd* h : this->hdd)
		{
			if (h != nullptr)
			{
				laptop->AddHdd((Hdd*)h->Clone());
			}
		}




		
		return laptop;
	}
};




































//	Класс палитры типичных конфигураций
class PcPrototypes
{
	// Словарь, в котором хранятся прототипы конфигураций
	map<string, PersonalComputer*> pcprototypes;
public:
	PcPrototypes()
	{
		// инициализация палитры прототипами конфигураций
		InitializePcPrototypes();
	}


	// Доступ к прототипу конфигурации по его имени
	PersonalComputer* operator[](string key)
	{
		return  pcprototypes[key];
	}
	void InitializePcPrototypes()
	{
		pcprototypes["Home"] = CreateHomeConfig();
		pcprototypes["Office"] = CreateOfficeConfig();
		pcprototypes["Game"] = CreateGamerConfig();
		

	}

	PersonalComputer* CreateHomeConfig()
	{
		PersonalComputer* config = new PersonalComputer();

		Box* box = new Box();
		box->SetColor("Silver");
		config->SetBox(box);

		Mainboard* mainboard = new Mainboard();
		mainboard->SetProducer("ATI");
		mainboard->SetBusFrequency(800);
		mainboard->SetVideoCard(nullptr);
		config->SetMainboard(mainboard);

		Processor* processor = new Processor();
		processor->SetProducer("Intel");
		processor->SetCoreCount(2);
		processor->SetFrequency(3);
		config->SetProcessor(processor);

		VideoCard* videocard = new VideoCard();
		videocard->SetProducer("ATI");
		videocard->SetVolume(1024);
		config->SetVideoCard(videocard);

		Hdd* hdd = new Hdd();
		hdd->SetProducer("Samsung");
		hdd->SetType("SATA");
		hdd->SetVolume(500);
		config->AddHdd(hdd);

		Memory* memory = new Memory();
		memory->SetType("DDR2");
		memory->SetVolume(2);
		config->AddMemory(memory);

		return config;
	}

	PersonalComputer* CreateOfficeConfig()
	{
		PersonalComputer* config = new PersonalComputer();

		Box* box = new Box();
		box->SetColor("White");
		config->SetBox(box);

		Mainboard* mainboard = new Mainboard();
		mainboard->SetProducer("Albatron");
		mainboard->SetBusFrequency(800);

		VideoCard* videocard = new VideoCard();
		videocard->SetProducer("nVidia");
		videocard->SetVolume(1024);
		mainboard->SetVideoCard(videocard);
		config->SetMainboard(mainboard);

		Processor* processor = new Processor();
		processor->SetProducer("AMD");
		processor->SetCoreCount(1);
		processor->SetFrequency(1.8);
		config->SetProcessor(processor);

		Hdd* hdd = new Hdd();
		hdd->SetProducer("LG");
		hdd->SetType("SATA");
		hdd->SetVolume(160);
		config->AddHdd(hdd);

		Memory* memory = new Memory();
		memory->SetType("DDR2");
		memory->SetVolume(1);
		config->AddMemory(memory);

		config->SetVideoCard(nullptr);

		return config;
	}

	PersonalComputer* CreateGamerConfig()
	{
		PersonalComputer* config = new PersonalComputer();

		Box* box = new Box();
		box->SetColor("Black");
		config->SetBox(box);

		Mainboard* mainboard = new Mainboard();
		mainboard->SetProducer("Asus");
		mainboard->SetBusFrequency(800);
		mainboard->SetVideoCard(nullptr);
		config->SetMainboard(mainboard);

		Processor* processor = new Processor();
		processor->SetProducer("Intel");
		processor->SetCoreCount(4);
		processor->SetFrequency(4);
		config->SetProcessor(processor);

		VideoCard* videocard = new VideoCard();
		videocard->SetProducer("nVidia");
		videocard->SetVolume(1024);
		config->SetVideoCard(videocard);

		Hdd* hdd = new Hdd();
		hdd->SetProducer("WD");
		hdd->SetType("SATA2");
		hdd->SetVolume(1024);
		config->AddHdd(hdd);

		Memory* memory = new Memory();
		memory->SetType("DDR2");
		memory->SetVolume(4);
		config->AddMemory(memory);

		return config;
	}
};

void PrintPc(PersonalComputer *pc)//что делает клиент.Вывод данных
{
	cout << "PC configuration: " << endl;
	cout << "Box: " << pc->GetBox()->GetColor() << endl;
	cout << "Mainboard: " << pc->GetMainboard()->GetProducer() << pc->GetMainboard()->GetBusFrequency() << " MHz" << endl;
	if (pc->GetMainboard()->GetVideoCard() != nullptr)
	{
		cout << "Integrated VideoCard: " << pc->GetMainboard()->GetVideoCard()->GetProducer()
			 << pc->GetMainboard()->GetVideoCard()->GetVolume() << " Mb" << endl;
	}
	cout << "Processor: " << pc->GetProcessor()->GetProducer()
		 << pc->GetProcessor()->GetFrequency() << " GHz "
		 << pc->GetProcessor()->GetCoreCount() << " core" << endl;
	cout << "Memories: ";
	for(Memory *m : pc->GetMemories())
	{
		cout << m->GetType() << "  " << m->GetVolume() << " Gb\n";
	}
	cout << "Hdds: ";
	for(Hdd *h : pc->GetHdd())
	{
		cout << h->GetProducer() <<"  " << h->GetType() << "  " << h->GetVolume() << " Gb\n";
	}
	
	if (pc->GetVideoCard() != nullptr)
	{
		cout << "VideoCard: ";
		cout << pc->GetVideoCard()->GetProducer() << "  " << pc->GetVideoCard()->GetVolume() << " Mb\n";
	}
}




//	Класс палитры типичных конфигураций
class LaptopPrototypes
{
	// Словарь, в котором хранятся прототипы конфигураций
	map<string, Laptop*> laptopPrototypes;
public:
	LaptopPrototypes()
	{
		// инициализация палитры прототипами конфигураций
		InitializeLaptopPrototypes();
	}


	// Доступ к прототипу конфигурации по его имени
	Laptop* operator[](string key)
	{
		return  laptopPrototypes[key];
	}
	void InitializeLaptopPrototypes()
	{
		laptopPrototypes["Programming"] = CreateLaptop();

	}


	Laptop* CreateLaptop()
	{
		Laptop* config = new Laptop();

		Box* box = new Box();
		box->SetColor("Grey");
		config->SetBox(box);

		Mainboard* mainboard = new Mainboard();
		mainboard->SetProducer("Lenovo");
		mainboard->SetBusFrequency(800);

		VideoCard* videocard = new VideoCard();
		videocard->SetProducer("nVidia");
		videocard->SetVolume(1024);
		mainboard->SetVideoCard(videocard);
		config->SetMainboard(mainboard);

		Processor* processor = new Processor();
		processor->SetProducer("AMD");
		processor->SetCoreCount(1);
		processor->SetFrequency(1.8);
		config->SetProcessor(processor);

		Hdd* hdd = new Hdd();
		hdd->SetProducer("LG");
		hdd->SetType("SATA");
		hdd->SetVolume(160);
		config->AddHdd(hdd);

		Memory* memory = new Memory();
		memory->SetType("DDR4");
		memory->SetVolume(1);
		config->AddMemory(memory);

		config->SetVideoCard(nullptr);



		Web* web = new Web();
		web->SetColor("Black");
		web->SetVideoResolution("1280×720");
		config->SetWeb(web);

		Mouse* mouse = new Mouse();
		mouse->SetColor("White");
		mouse->SetSubmission("Wireless");
		config->SetMouse(mouse);

		//Mouse
		//string color;
		//string submission;
		return config;
	}
};






//	Класс палитры типичных конфигураций
class MobilePrototypes
{
	// Словарь, в котором хранятся прототипы конфигураций
	map<string, Mobile*> mobilePrototypes;
public:
	MobilePrototypes()
	{
		// инициализация палитры прототипами конфигураций
		InitializeMobilePrototypes();
	}


	// Доступ к прототипу конфигурации по его имени
	Mobile* operator[](string key)
	{
		return  mobilePrototypes[key];
	}
	void InitializeMobilePrototypes()
	{
		mobilePrototypes["Smartphone"] = CreateMobile();

	}



	Mobile* CreateMobile()
	{
		Mobile* config = new Mobile();

		Box* box = new Box();
		box->SetColor("Blue");
		config->SetBox(box);

		Mainboard* mainboard = new Mainboard();
		mainboard->SetProducer("Samsung");
		mainboard->SetBusFrequency(800);
		mainboard->SetVideoCard(nullptr);
		config->SetMainboard(mainboard);

		Processor* processor = new Processor();
		processor->SetProducer("Qualcomm Snapdragon 778G");
		processor->SetCoreCount(4);
		processor->SetFrequency(4);
		config->SetProcessor(processor);


		Memory* memory = new Memory();
		memory->SetType("RAM");
		memory->SetVolume(8);
		config->AddMemory(memory);

		Web* web = new Web();
		web->SetColor("Black");
		web->SetVideoResolution("1280×720");
		config->SetWeb(web);

		return config;
	}
};









void PrintMobile(Mobile* mob)//что делает клиент.Вывод данных
{



	/*Web* web;


	string color;
	string videoResolution;*/



	cout << "Mobile configuration: " << endl;
	cout << "Box: " << mob->GetBox()->GetColor() << endl;
	cout << "Mainboard: " << mob->GetMainboard()->GetProducer() << mob->GetMainboard()->GetBusFrequency() << " MHz" << endl;


	cout << "Processor: " << mob->GetProcessor()->GetProducer()
		<< mob->GetProcessor()->GetFrequency() << " GHz "
		<< mob->GetProcessor()->GetCoreCount() << " core" << endl;

	cout << "WebCamera: " << mob->GetWeb()->GetColor() << mob->GetWeb()->GetVideoResolution() << endl;



	cout << "Memories: ";
	for (Memory* m : mob->GetMemories())
	{
		cout << m->GetType() << "  " << m->GetVolume() << " Gb\n";
	}
	


}





void PrintLaptop(Laptop* laptop)//что делает клиент.Вывод данных

{


	/*Web* web;


	string color;
	string videoResolution;*/



	//Mouse
	//string color;
	//string submission;

	cout << "PC configuration: " << endl;
	cout << "Box: " << laptop->GetBox()->GetColor() << endl;
	cout << "Mainboard: " << laptop->GetMainboard()->GetProducer() << laptop->GetMainboard()->GetBusFrequency() << " MHz" << endl;
	if (laptop->GetMainboard()->GetVideoCard() != nullptr)
	{
		cout << "Integrated VideoCard: " << laptop->GetMainboard()->GetVideoCard()->GetProducer()
			<< laptop->GetMainboard()->GetVideoCard()->GetVolume() << " Mb" << endl;
	}
	cout << "Processor: " << laptop->GetProcessor()->GetProducer()
		<< laptop->GetProcessor()->GetFrequency() << " GHz "
		<< laptop->GetProcessor()->GetCoreCount() << " core" << endl;
	cout << "Memories: ";
	for (Memory* m : laptop->GetMemories())
	{
		cout << m->GetType() << "  " << m->GetVolume() << " Gb\n";
	}
	cout << "Hdds: ";
	for (Hdd* h : laptop->GetHdd())
	{
		cout << h->GetProducer() << "  " << h->GetType() << "  " << h->GetVolume() << " Gb\n";
	}

	if (laptop->GetVideoCard() != nullptr)
	{
		cout << "VideoCard: ";
		cout << laptop->GetVideoCard()->GetProducer() << "  " << laptop->GetVideoCard()->GetVolume() << " Mb\n";
	}


	cout << "WebCamera: " << laptop->GetWeb()->GetColor() << laptop->GetWeb()->GetVideoResolution() << endl;
	cout << "Mouse: " << laptop->GetMouse()->GetColor() << laptop->GetMouse()->GetSubmission() << endl;

}









int main()
{
	// Ввести имя прототипа конфигурации
	cout << "-Home" << endl;
	cout << "-Office" << endl;
	cout << "-Game" << endl;
	cout << "Enter config prototype name to computer: ";
	string prototypeName;
	cin >> prototypeName;
	PcPrototypes pc;
	// Получение прототипа конфигурации из палитры по его имени
	PersonalComputer *prototype = pc[prototypeName];
	if (prototype != nullptr)
	{
		// Создание конфигурации на основе выбранного прототипа
		PersonalComputer *pc = dynamic_cast<PersonalComputer*>(prototype->Clone());
		// Вывод состава конфигурации на консоль
		PrintPc(pc);
	}
	else
	{
		cout << "Error: incorrect config name";
	}



	// Ввести имя прототипа конфигурации
	cout << "-Smartphone" << endl;

	cout << "Enter config prototype name to mobile: ";
	string prototypeNameMobile;
	cin >> prototypeNameMobile;
	MobilePrototypes mobil;
	// Получение прототипа конфигурации из палитры по его имени
	Mobile* prototypeMob = mobil[prototypeNameMobile];
	if (prototypeMob != nullptr)
	{
		// Создание конфигурации на основе выбранного прототипа
		Mobile* mobil = dynamic_cast<Mobile*>(prototypeMob->Clone());
		// Вывод состава конфигурации на консоль
		PrintMobile(mobil);
	}
	else
	{
		cout << "Error: incorrect config name of mobile";
	}





	// Ввести имя прототипа конфигурации
	cout << "-Programming" << endl;
	
	cout << "Enter config prototype name to laptop: ";
	string prototypeNameLaptop;
	cin >> prototypeNameLaptop;

	LaptopPrototypes lap;
	// Получение прототипа конфигурации из палитры по его имени
	Laptop* prototypeLap = lap[prototypeNameLaptop];
	if (prototypeLap != nullptr)
	{
		// Создание конфигурации на основе выбранного прототипа
		Laptop* lap = dynamic_cast<Laptop*>(prototypeLap->Clone());
		// Вывод состава конфигурации на консоль
		PrintLaptop(lap);
	}
	else
	{
		cout << "Error: incorrect config name of laptop";
	}






	system("pause");
}

