# QtCpuInfo
QtCpuInfo reads periodically /proc/cpuinfo file in Linux and displays number of CPU cores as QML CircularGauge controls. It also displays CPU core clock frequency and identifier and system processor name.

## Installation

Following dependencies are needed

```Dependencies
Linux operation system. Ubuntu 16.04 is preferred
Qt5.8 (C++11 standard support needed) or above
QtCreator with C++11 standard support
```
Download and install Qt Creator in Linux

```QtCreator
https://info.qt.io/download-qt-for-application-development
```

Clone QtCpuInfo project from GitHub

```CloneProject
cd ~
mkdir dev
cd dev
git clone https://github.com/username/QtCpuInfo.git
```

Build project and run application

```BuildApplication
Open Qt Creator

Select 'Open Project'

Locate and open QtCpuInfo.pro file in /home/user/dev/QtCpuInfo directory

Build project (Build -> Rebuild All)

Run project (Ctrl + R)
```
## Test environment

Application was tested with Qt5.8 and QtCreator 4.2.1 running on Ubuntu 16.04 x64

## Support

If you face any problems or have some improvement ideas you can always create a Github issue in main repository
