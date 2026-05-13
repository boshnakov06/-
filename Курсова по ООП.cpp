#include <iostream>
#include <string>
using namespace std;

class Device {
protected:
    string brand;
    double price;

public:
    Device() : brand("Unknown"), price(0.0) {}
    Device(string b, double p = 100.0) : brand(b), price(p) {}

    virtual ~Device() {}

    virtual double getAnnualCost() = 0;
    virtual double getPerformanceScore() = 0;

    string getBrand() { return brand; }
};

// Computer
class Computer : public Device {
protected:
    int ram;
    string cpu;

public:
    Computer() : Device(), ram(8), cpu("Intel i5") {}
    Computer(string b, double p, int r, string c = "AMD Ryzen 5")
        : Device(b, p), ram(r), cpu(c) {}

    double getAnnualCost() override {
        return price * 1.10 + ram * 5;
    }

    double getPerformanceScore() override {
        return ram * 10;
    }
};

// SmartDevice
class SmartDevice : public Device {
protected:
    string os;
    bool has5G;

public:
    SmartDevice() : Device(), os("Android"), has5G(false) {}
    SmartDevice(string b, double p, string o, bool g = true)
        : Device(b, p), os(o), has5G(g) {}

    double getAnnualCost() override {
        if (has5G == true) {
            return price + 120;
        } else {
            return price + 60;
        }
    }

    double getPerformanceScore() override {
        if (has5G == true) {
            return 80;
        } else {
            return 60;
        }
    }
};

// Laptop
class Laptop : public Computer {
protected:
    double weight;
    int batteryCycle;

public:
    Laptop() : Computer(), weight(1.5), batteryCycle(0) {}
    Laptop(string b, double p, int r, string c, double w, int cycles = 1)
        : Computer(b, p, r, c), weight(w), batteryCycle(cycles) {}

    double getAnnualCost() override {
        return price * 1.08 + batteryCycle * 2;
    }

    double getPerformanceScore() override {
        return ram * 12 - weight * 2;
    }
};

// Smartphone
class Smartphone : public SmartDevice {
private:
    int camerasCount;
    bool faceID;

public:
    Smartphone() : SmartDevice(), camerasCount(1), faceID(false) {}
    Smartphone(string b, double p, string o, bool g, int cam, bool f = true)
        : SmartDevice(b, p, o, g), camerasCount(cam), faceID(f) {}

    double getAnnualCost() override {
        double result = price + camerasCount * 20;

        if (faceID == true) {
            result = result + 50;
        }

        return result;
    }

    double getPerformanceScore() override {
        double result = camerasCount * 15;

        if (faceID == true) {
            result = result + 30;
        } else {
            result = result + 10;
        }

        return result;
    }
};

// Desktop
class Desktop : public Computer {
private:
    int powerSupply;
    bool liquidCooled;

public:
    Desktop() : Computer(), powerSupply(500), liquidCooled(false) {}
    Desktop(string b, double p, int r, string c, int watts, bool liquid = false)
        : Computer(b, p, r, c), powerSupply(watts), liquidCooled(liquid) {}

    double getAnnualCost() override {
        double result = price + powerSupply * 0.5;

        if (liquidCooled == true) {
            result = result + 200;
        }

        return result;
    }

    double getPerformanceScore() override {
        double result = ram * 15;

        if (liquidCooled == true) {
            result = result + 50;
        } else {
            result = result + 20;
        }

        return result;
    }
};

// GamingLaptop
class GamingLaptop : public Laptop {
private:
    string gpu;
    int rgbZones;

public:
    GamingLaptop() : Laptop(), gpu("Integrated"), rgbZones(1) {}
    GamingLaptop(string b, double p, int r, string c, double w, int cyc, string g, int rgb = 4)
        : Laptop(b, p, r, c, w, cyc), gpu(g), rgbZones(rgb) {}

    double getAnnualCost() override {
        return price + rgbZones * 15 + weight * 25;
    }

    double getPerformanceScore() override {
        return ram * 20 + rgbZones * 5;
    }
};

int main() {
    Device* devices[6];

    devices[0] = new Computer("HP Workstation", 2500, 32, "Intel i9");
    devices[1] = new Laptop("MacBook Air", 2000, 16, "M2", 1.2, 15);
    devices[2] = new SmartDevice("Xiaomi Hub", 150, "MUI", false);
    devices[3] = new Smartphone("iPhone 15 Pro", 2200, "iOS", true, 3);
    devices[4] = new Desktop("Custom Gaming Rig", 3500, 64, "Ryzen 9", 850, true);
    devices[5] = new GamingLaptop("Asus ROG Strix", 4200, 32, "i7", 2.8, 45, "RTX 4080");

    for (int i = 0; i < 6; i++) {
        cout << "Device: " << devices[i]->getBrand() << endl;
        cout << "Annual Cost: " << devices[i]->getAnnualCost() << endl;
        cout << "Performance Score: " << devices[i]->getPerformanceScore() << endl;
        cout << "-------------------------------------" << endl;
    }

    for (int i = 0; i < 6; i++) {
        delete devices[i];
    }

    return 0;
}class Laptop : public Computer {
protected:
    double weight;
    int batteryCycle;

public:
    Laptop() : Computer(), weight(1.5), batteryCycle(0) {}
    Laptop(string b, double p, int r, string c, double w, int cycles = 1)
        : Computer(b, p, r, c), weight(w), batteryCycle(cycles) {}

    double getAnnualCost() override {
        return price * 1.08 + batteryCycle * 2;
    }

    double getPerformanceScore() override {
        return ram * 12 - weight * 2;
    }
};

// Smartphone
class Smartphone : public SmartDevice {
private:
    int camerasCount;
    bool faceID;

public:
    Smartphone() : SmartDevice(), camerasCount(1), faceID(false) {}
    Smartphone(string b, double p, string o, bool g, int cam, bool f = true)
        : SmartDevice(b, p, o, g), camerasCount(cam), faceID(f) {}

    double getAnnualCost() override {
        return price + camerasCount * 20 + (faceID ? 50 : 0);
    }

    double getPerformanceScore() override {
        return camerasCount * 15 + (faceID ? 30 : 10);
    }
};

// Desktop
class Desktop : public Computer {
private:
    int powerSupply;
    bool liquidCooled;

public:
    Desktop() : Computer(), powerSupply(500), liquidCooled(false) {}
    Desktop(string b, double p, int r, string c, int watts, bool liquid = false)
        : Computer(b, p, r, c), powerSupply(watts), liquidCooled(liquid) {}

    double getAnnualCost() override {
        return price + powerSupply * 0.5 + (liquidCooled ? 200 : 0);
    }

    double getPerformanceScore() override {
        return ram * 15 + (liquidCooled ? 50 : 20);
    }
};

// GamingLaptop
class GamingLaptop : public Laptop {
private:
    string gpu;
    int rgbZones;

public:
    GamingLaptop() : Laptop(), gpu("Integrated"), rgbZones(1) {}
    GamingLaptop(string b, double p, int r, string c, double w, int cyc, string g, int rgb = 4)
        : Laptop(b, p, r, c, w, cyc), gpu(g), rgbZones(rgb) {}

    double getAnnualCost() override {
        return price + rgbZones * 15 + weight * 25;
    }

    double getPerformanceScore() override {
        return ram * 20 + rgbZones * 5;
    }
};

int main() {
    Device* devices[6];

    devices[0] = new Computer("HP Workstation", 2500, 32, "Intel i9");
    devices[1] = new Laptop("MacBook Air", 2000, 16, "M2", 1.2, 15);
    devices[2] = new SmartDevice("Xiaomi Hub", 150, "MUI", false);
    devices[3] = new Smartphone("iPhone 15 Pro", 2200, "iOS", true, 3);
    devices[4] = new Desktop("Custom Gaming Rig", 3500, 64, "Ryzen 9", 850, true);
    devices[5] = new GamingLaptop("Asus ROG Strix", 4200, 32, "i7", 2.8, 45, "RTX 4080");

    for (int i = 0; i < 6; i++) {
        cout << "Device: " << devices[i]->getBrand() << endl;
        cout << "Annual Cost: " << devices[i]->getAnnualCost() << endl;
        cout << "Performance Score: " << devices[i]->getPerformanceScore() << endl;
        cout << "-------------------------------------" << endl;
    }

    for (int i = 0; i < 6; i++) {
        delete devices[i];
    }

    return 0;
}};

class Smartphone : public SmartDevice {
private:
    int camerasCount;
    bool faceID;

public:
    Smartphone() : SmartDevice(), camerasCount(1), faceID(false) {}
    Smartphone(string b, double p, string o, bool g, int cam, bool f = true) 
        : SmartDevice(b, p, o, g), camerasCount(cam), faceID(f) {}

    void takePhoto() { cout << brand << " is taking a photo with " << camerasCount << " cameras." << endl; }
    void toggleAirplaneMode() { cout << "Airplane mode toggled on " << brand << endl; }

    void printInfo() override {
        cout << "\n--- [Smartphone] ---" << endl;
        cout << "Brand: " << brand << ", OS: " << os 
             << ", Cameras: " << camerasCount << ", FaceID: " << (faceID ? "Yes" : "No") << endl;
    }
};

class Desktop : public Computer {
private:
    int powerSupply; 
    bool liquidCooled;

public:
    Desktop() : Computer(), powerSupply(500), liquidCooled(false) {}
    Desktop(string b, double p, int r, string c, int watts, bool liquid = false) 
        : Computer(b, p, r, c), powerSupply(watts), liquidCooled(liquid) {}

    void overclock() { cout << "Overclocking desktop " << brand << " CPU!" << endl; }
    void cleanDust() { cout << "Cleaning dust from the " << powerSupply << "W power supply." << endl; }

    void printInfo() override {
        cout << "\n--- [Desktop] ---" << endl;
        cout << "Brand: " << brand << ", PSU: " << powerSupply 
             << "W, Liquid Cooled: " << (liquidCooled ? "Yes" : "No") << endl;
    }
};

class GamingLaptop : public Laptop {
private:
    string gpu;
    int rgbZones;

public:
    GamingLaptop() : Laptop(), gpu("Integrated"), rgbZones(1) {}
    GamingLaptop(string b, double p, int r, string c, double w, int cyc, string g, int rgb = 4) 
        : Laptop(b, p, r, c, w, cyc), gpu(g), rgbZones(rgb) {}

    void boostFans() { cout << "Fans at 100% for GPU: " << gpu << endl; }
    void changeRGB() { cout << "Changing colors in " << rgbZones << " RGB zones." << endl; }

    void printInfo() override {
        cout << "\n--- [GamingLaptop] ---" << endl;
        cout << "Brand: " << brand << ", GPU: " << gpu 
             << ", RGB Zones: " << rgbZones << ", Weight: " << weight << "kg" << endl;
    }
};

int main() {
 
    Device* devices[6];

    devices[0] = new Computer("HP Workstation", 2500, 32, "Intel i9");
    devices[1] = new Laptop("MacBook Air", 2000, 16, "M2", 1.2, 15);
    devices[2] = new SmartDevice("Xiaomi Hub", 150, "MUI", false);
    devices[3] = new Smartphone("iPhone 15 Pro", 2200, "iOS", true, 3);
    devices[4] = new Desktop("Custom Gaming Rig", 3500, 64, "Ryzen 9", 850, true);
    devices[5] = new GamingLaptop("Asus ROG Strix", 4200, 32, "i7", 2.8, 45, "RTX 4080");

    for (int i = 0; i < 6; i++) {
        devices[i]->printInfo();
        devices[i]->powerOn();
        devices[i]->checkBattery();
        
        cout << "------------------------------------------" << endl;
    }

    for (int i = 0; i < 6; i++) {
        delete devices[i];
    }

    return 0;
}
