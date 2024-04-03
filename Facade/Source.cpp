#include <iostream>
#include <string>
using namespace std;
/*
 * Фасад предоставляет унифицированный интерфейс вместо набора интерфейсов некоторой подсистемы.
 * Фасад определяет интерфейс более высокого уровня, который упрощает использование подсистемы.
 * Разбиение на подсистемы облегчает проектирование сложной системы в целом.
 * Общая цель всякого проектирования - свести к минимуму зависимость подсистем друг от друга и обмен информацией между ними.
 * Один из способов решения этой задачи - введение объекта фасад, предоставляющий единый упрощенный интерфейс к более сложным системным средствам.

 Классы подсистемы:
 - реализуют функциональность подсистемы;
 - выполняют работу, порученную объектом Facade;
 - ничего не «знают» о существовании фасада, то есть не хранят ссылок на него.
  */


class VideoCard//Видеокарта
{
public:
	void LaunchVideoCard()
	{
		cout << "Видеокарта: запуск\n";
	}

	void CheckingConnectionMonitor()
	{
		cout << "Видеокарта: проверка связи с монитором.\n";
	}
	void DisplaysDataRAM()
	{
		cout << "Видеокарта: вывод данных об оперативной памяти.\n";
	}

	void DisplaysOpticalDiscReader()
	{
		cout << "Видеокарта: вывод информации об устройстве чтения дисков.\n";
	}

	void DisplaysWinchester()
	{
		cout << "Видеокарта: вывод данных о винчестере.\n";
	}

	void ByeMessage()
	{
		cout << "Видео карта: вывести на монитор данные прощальное сообщение.\n";
	}

	
};





class RAM//оперативная память
{
public:
	void LaunchingDevicesRAM()
	{
		cout << "Оперативная память: запуск устройств.\n";
	}
	void MemoryAnalysis()
	{
		cout << "Оперативная память: анализ памяти.\n";
	}

	void MemoryDelete()
	{
		cout << "Оперативная память: очистка памяти.\n";
	}
};

class Winchester//Винчестер
{
public:
	void LaunchWinchester()
	{
		cout << "Винчестер: запуск.\n";
	}
	void CheckingBootSector()
	{
		cout << "Винчестер: проверка загрузочного сектора.\n";
	}


	void StopDevice()
	{
		cout << "Винчестер: остановка устройства.\n";
	}



};



class OpticalDiscReader//Устройство чтения оптических дисков
{
public:
	void LaunchOpticalDiscReader()
	{
		cout << "Устройство чтения оптических дисков: запуск.\n";
	}
	void CheckOpticalDiscReader()
	{
		cout << "Устройство чтения оптических дисков: проверка наличия диска.\n";
	}
	void ReturnOriginalPosition()
	{
		cout << "Устройство чтения дисков: вернуть в исходную позицию.\n";
	}
};


class powerUnit//блок питания
{
public:
	void ApplyPower()
	{
		cout << "Блок питания: подать питание.\n";
	}
	void ApplyPowerVideoCard()
	{
		cout << "Блок питания: подать питание на видеокарту.\n";
	}
	void ApplyPowerRAM()
	{
		cout << "Блок питания: подать питание на оперативную память.\n";
	}

	void ApplyPowerOpticalDiscReader()
	{
		cout << "Блок питания: подать питание на устройство чтения дисков.\n";
	}

	void ApplyPowerWinchester()
	{
		cout << "Блок питания: подать питание на винчестер.\n";
	}

	void StopPowerVideoCard()
	{
		cout << "Блок питания: прекратить питание видео карты.\n";
	}
	
	void StopPowerRAM()
	{
		cout << "Блок питания: прекратить питание оперативной памяти.\n";
	}
	void StopPowerOpticalDiscReader()
	{
		cout << "Блок питания: прекратить питание устройства чтения дисков.\n";
	}
	void StopPowerWinchester()
	{
		cout << "Блок питания: прекратить питание винчестера.\n";
	}

	void StopPower()
	{
		cout << "Блок питания: выключение.\n";
	}
};


class Sensors//Датчики
{
public:
	void  CheckVoltage()
	{
		cout << "Датчики: проверить напряжение.\n";
	}
	void  CheckTemperaturePowerSupply()
	{
		cout << "Датчики: проверить температуру в блоке питания.\n";
	}
	void  CheckTemperatureVideoCard()
	{
		cout << "Датчики: проверить температуру в видео карте.\n";
	}
	void  CheckTemperatureRAM()
	{
		cout << "Датчики: проверить температуру в оперативной памяти.\n";
	}
	void  CheckTemperatureALL()
	{
		cout << "Датчики: проверить температуру всех систем.\n";
	}

	
};







/*
 * Facade - фасад:
- «знает», каким классам подсистемы адресовать запрос;
- делегирует запросы клиентов подходящим объектам внутри подсистемы;
 */

class PCStudioFacade
{
	VideoCard videocard;
	RAM ram;
	Winchester hdd;
	OpticalDiscReader disc;
	powerUnit power;
	Sensors sensors;

public:
	PCStudioFacade(VideoCard vid, RAM ra, Winchester hd, OpticalDiscReader di, powerUnit pow, Sensors sens)
	{
		videocard = vid;
		ram = ra;
		hdd = hd;
		disc = di;
		power = pow;
		sensors = sens;
	}

	void Start()//фасад выполняет под копотом кучу всего о чем клиенту не надо знать
	{
		power.ApplyPower();
		sensors.CheckVoltage();
		sensors.CheckTemperaturePowerSupply();
		sensors.CheckTemperatureVideoCard();
		power.ApplyPowerVideoCard();
		videocard.LaunchVideoCard();
		videocard.CheckingConnectionMonitor();
		sensors.CheckTemperatureRAM();
		power.ApplyPowerRAM();
		ram.LaunchingDevicesRAM();
		ram.MemoryAnalysis();
		videocard.DisplaysDataRAM();
		power.ApplyPowerOpticalDiscReader();
		disc.LaunchOpticalDiscReader();
		disc.CheckOpticalDiscReader();
		videocard.DisplaysOpticalDiscReader();
		power.ApplyPowerWinchester();
		hdd.LaunchWinchester();
		hdd.CheckingBootSector();
		videocard.DisplaysWinchester();
		sensors.CheckTemperatureALL();
	}
	void Stop()
	{
		hdd.StopDevice();
		ram.MemoryDelete();
		ram.MemoryAnalysis();
		videocard.ByeMessage();
		disc.ReturnOriginalPosition();
		power.StopPowerVideoCard();
		power.StopPowerRAM();
		power.StopPowerOpticalDiscReader();
		power.StopPowerWinchester();
		sensors.CheckVoltage();
		power.StopPower();
	}
};

// Фасад предоставляет клиенту интерфейс более высокого уровня, который упрощает использование подсистемы.
class Programmer
{
public:
	void CreateApplication(PCStudioFacade facade)
	{
		facade.Start();
		facade.Stop();
	}
};

int main()

{

	setlocale(LC_ALL, "Russian");

	VideoCard videocard;
	RAM ram;
	Winchester hdd;
	OpticalDiscReader disc;
	powerUnit power;
	Sensors sensors;

	PCStudioFacade ide(videocard, ram, hdd, disc, power, sensors);

	Programmer programmer;
	programmer.CreateApplication(ide);

	system("pause");
	return 0;
}