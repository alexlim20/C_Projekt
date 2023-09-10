#include <iostream>
#include <iomanip>
#include "testlevel.h"
#include "Point.h"
#include "RGBColor.h"
#include "Switch.h"
#include "WinAdapt.h"
#include "LogicGateAND.h"
#include "LogicGateNAND.h"
#include "LogicGateOR.h"
#include "LogicGateXOR.h"


#if test_level > 0
#include "Wire.h"
#endif

#if test_level > 1
#include "LogicGate.h"
#endif

#if test_level > 4
#include "LogicGateSwitch.h"
#endif

using namespace std;

/* Diese Makrodefinition beinhaltet einen kleinen Codegenerator. Das Makro wird
 * mit zwei Parametern aufgerufen, nämlich der Bedingung, welche getestet werden soll, und
 * dem Text, der zur Erläuterung ausgegeben werden soll. Daraus wird dann je nach
 * Testergebnis eine Meldung ausgegeben und ggf. das Programm abgebrochen.
 */
#define test(cond, description) {cout <<"   " << setw(50) << left << description;\
    if(cond) {cout << " OK"<<endl;} else {cout << " FAILED"<<endl;abort();}}


#if test_level == 0
Switch TestSwitch(Point(100, 100), "On", "Off");
#endif

#if test_level == 1
Wire TestWire[] = {
                                    Wire(Point(20, 20), Point(70,70)),
                                    Wire(Point(120, 70), Point(170,20)),
                                    Wire(Point(90, 80), Point(90,120)),
                                    Wire(Point(30, 100), Point(60,100)),
                                    Wire(Point(80, 150), Point(130,130)),
                                };
#endif

#if test_level == 2
LogicGate TestGate[] = {
                                    LogicGate("??", Point(20, 20), nullptr, nullptr),
                                    LogicGate("??", Point(20, 120), nullptr, nullptr),
                                    LogicGate("??", Point(190, 70), &TestGate[0], &TestGate[1]),
                                };
#endif

#if test_level == 4
LogicGate *TestGate[] = {
                                    new LogicGateAND(Point(20, 20), nullptr, nullptr),
                                    new LogicGateOR(Point(20, 120), nullptr, nullptr),
                                    new LogicGateXOR(Point(190, 100), TestGate[0], TestGate[1]),
                                    new LogicGateNAND(Point(330, 60), TestGate[0], TestGate[2]),
                                };
#endif

#if test_level == 5
LogicGateSwitch TestSwitch("Power", Point(20,20));
#endif

#if test_level == 6
LogicGateSwitch *TestSwitch[] = {
                                    new LogicGateSwitch("IN1", Point(20, 10)),
                                    new LogicGateSwitch("IN2", Point(20, 60)),
                                    new LogicGateSwitch("IN3", Point(20, 110)),
                                    new LogicGateSwitch("IN4", Point(20, 160))
                                };

LogicGate *TestGate[] = {
                                    new LogicGateAND(Point(220, 20), TestSwitch[0], TestSwitch[1]),
                                    new LogicGateOR(Point(220, 120), TestSwitch[2], TestSwitch[3]),
                                    new LogicGateXOR(Point(390, 100), TestGate[0], TestGate[1]),
                                    new LogicGateNAND(Point(530, 60), TestGate[0], TestGate[2]),
                                };
#endif

#if test_level ==7
LogicGateSwitch *DigitalSwitch[] = {
                                    new LogicGateSwitch("IN1", Point(20, 10)),
                                    new LogicGateSwitch("IN2", Point(20, 60)),
                                    new LogicGateSwitch("IN3", Point(20, 110)),
                                    new LogicGateSwitch("IN4", Point(20, 160)),
                                    new LogicGateSwitch("IN5", Point(20, 210)),
                                    new LogicGateSwitch("IN6", Point(20, 260)),
                                    new LogicGateSwitch("IN7", Point(20, 310)),
                                    new LogicGateSwitch("IN8", Point(20, 360))
                                };

LogicGate *DigitalGate[] = {
                                    new LogicGateAND(Point(220, 30), DigitalSwitch[0], DigitalSwitch[1]),
                                    new LogicGateOR(Point(220, 140), DigitalSwitch[2], DigitalSwitch[3]),
                                    new LogicGateXOR(Point(220, 230), DigitalSwitch[4], DigitalSwitch[5]),
                                    new LogicGateNAND(Point(220, 330), DigitalSwitch[6], DigitalSwitch[7]),
                                    new LogicGateXOR(Point(390, 70), DigitalGate[0], DigitalGate[1]),
                                    new LogicGateOR(Point(390, 190), DigitalGate[1], DigitalGate[2]),
                                    new LogicGateAND(Point(390, 310), DigitalGate[2], DigitalGate[3]),
                                    new LogicGateNAND(Point(530, 90), DigitalGate[4], DigitalGate[5]),
                                    new LogicGateXOR(Point(530, 270), DigitalGate[5], DigitalGate[6]),
                                    new LogicGateAND(Point(640, 180), DigitalGate[7], DigitalGate[8])
                                };
#endif // test_level 7


void VtlZyk(void)
{
}

void VtlMouse(int X, int Y)
{
#if test_level == 0
    TestSwitch.onMouse(Point(X, Y));
#endif
#if test_level == 5
    TestSwitch.onMouse(Point(X, Y));
#endif
#if test_level == 6
    for (unsigned int i=0; i < (sizeof(TestSwitch)/sizeof(LogicGateSwitch*)); ++i)
    {
    TestSwitch[i]->onMouse(Point(X, Y));
    }
#endif

#if test_level == 7
    for (unsigned int i=0; i < (sizeof(DigitalSwitch)/sizeof(LogicGateSwitch*)); ++i)
    {
    DigitalSwitch[i]->onMouse(Point(X, Y));
    }
#endif
}

void VtlKeyHit(int key)
{
}

void VtlInit(void)
{
    setWindowTitle("Digitalschaltung Sommer 2022");
    setUpdateInterval(200);
    cout << "test_level: " << test_level << endl;
}

void VtlPaint(int xl, int yo, int xr, int yu)
{
#if test_level == 0
    TestSwitch.show();
#endif
#if test_level == 1
    for (int i=0; i < (sizeof(TestWire)/sizeof(Wire)); ++i)
    {
        TestWire[i].show();
    }
#endif
#if test_level == 2
    TestGate[2].show();
#endif
#if test_level == 4
    TestGate[3]->show();
#endif
#if test_level == 5
    TestSwitch.show();
#endif
#if test_level == 6
        TestGate[3]->show();
#endif

#if test_level == 7
        DigitalGate[9]->show();
#endif
}

