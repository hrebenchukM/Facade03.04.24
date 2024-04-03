#include <iostream>
#include <string>
using namespace std;
/*
 * ����� ������������� ��������������� ��������� ������ ������ ����������� ��������� ����������.
 * ����� ���������� ��������� ����� �������� ������, ������� �������� ������������� ����������.
 * ��������� �� ���������� ��������� �������������� ������� ������� � �����.
 * ����� ���� ������� �������������� - ������ � �������� ����������� ��������� ���� �� ����� � ����� ����������� ����� ����.
 * ���� �� �������� ������� ���� ������ - �������� ������� �����, ��������������� ������ ���������� ��������� � ����� ������� ��������� ���������.

 ������ ����������:
 - ��������� ���������������� ����������;
 - ��������� ������, ���������� �������� Facade;
 - ������ �� ������ � ������������� ������, �� ���� �� ������ ������ �� ����.
  */


class VideoCard//����������
{
public:
	void LaunchVideoCard()
	{
		cout << "����������: ������\n";
	}

	void CheckingConnectionMonitor()
	{
		cout << "����������: �������� ����� � ���������.\n";
	}
	void DisplaysDataRAM()
	{
		cout << "����������: ����� ������ �� ����������� ������.\n";
	}

	void DisplaysOpticalDiscReader()
	{
		cout << "����������: ����� ���������� �� ���������� ������ ������.\n";
	}

	void DisplaysWinchester()
	{
		cout << "����������: ����� ������ � ����������.\n";
	}

	void ByeMessage()
	{
		cout << "����� �����: ������� �� ������� ������ ���������� ���������.\n";
	}

	
};





class RAM//����������� ������
{
public:
	void LaunchingDevicesRAM()
	{
		cout << "����������� ������: ������ ���������.\n";
	}
	void MemoryAnalysis()
	{
		cout << "����������� ������: ������ ������.\n";
	}

	void MemoryDelete()
	{
		cout << "����������� ������: ������� ������.\n";
	}
};

class Winchester//���������
{
public:
	void LaunchWinchester()
	{
		cout << "���������: ������.\n";
	}
	void CheckingBootSector()
	{
		cout << "���������: �������� ������������ �������.\n";
	}


	void StopDevice()
	{
		cout << "���������: ��������� ����������.\n";
	}



};



class OpticalDiscReader//���������� ������ ���������� ������
{
public:
	void LaunchOpticalDiscReader()
	{
		cout << "���������� ������ ���������� ������: ������.\n";
	}
	void CheckOpticalDiscReader()
	{
		cout << "���������� ������ ���������� ������: �������� ������� �����.\n";
	}
	void ReturnOriginalPosition()
	{
		cout << "���������� ������ ������: ������� � �������� �������.\n";
	}
};


class powerUnit//���� �������
{
public:
	void ApplyPower()
	{
		cout << "���� �������: ������ �������.\n";
	}
	void ApplyPowerVideoCard()
	{
		cout << "���� �������: ������ ������� �� ����������.\n";
	}
	void ApplyPowerRAM()
	{
		cout << "���� �������: ������ ������� �� ����������� ������.\n";
	}

	void ApplyPowerOpticalDiscReader()
	{
		cout << "���� �������: ������ ������� �� ���������� ������ ������.\n";
	}

	void ApplyPowerWinchester()
	{
		cout << "���� �������: ������ ������� �� ���������.\n";
	}

	void StopPowerVideoCard()
	{
		cout << "���� �������: ���������� ������� ����� �����.\n";
	}
	
	void StopPowerRAM()
	{
		cout << "���� �������: ���������� ������� ����������� ������.\n";
	}
	void StopPowerOpticalDiscReader()
	{
		cout << "���� �������: ���������� ������� ���������� ������ ������.\n";
	}
	void StopPowerWinchester()
	{
		cout << "���� �������: ���������� ������� ����������.\n";
	}

	void StopPower()
	{
		cout << "���� �������: ����������.\n";
	}
};


class Sensors//�������
{
public:
	void  CheckVoltage()
	{
		cout << "�������: ��������� ����������.\n";
	}
	void  CheckTemperaturePowerSupply()
	{
		cout << "�������: ��������� ����������� � ����� �������.\n";
	}
	void  CheckTemperatureVideoCard()
	{
		cout << "�������: ��������� ����������� � ����� �����.\n";
	}
	void  CheckTemperatureRAM()
	{
		cout << "�������: ��������� ����������� � ����������� ������.\n";
	}
	void  CheckTemperatureALL()
	{
		cout << "�������: ��������� ����������� ���� ������.\n";
	}

	
};







/*
 * Facade - �����:
- ������, ����� ������� ���������� ���������� ������;
- ���������� ������� �������� ���������� �������� ������ ����������;
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

	void Start()//����� ��������� ��� ������� ���� ����� � ��� ������� �� ���� �����
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

// ����� ������������� ������� ��������� ����� �������� ������, ������� �������� ������������� ����������.
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