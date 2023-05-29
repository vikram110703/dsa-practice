class ParkingSystem {
public:
    int b,m,s;
    ParkingSystem(int big, int medium, int small) {
      b=big;
      m=medium;
      s=small;
        
    }
    
    bool addCar(int carType) {
        bool isPossible=false;
        if(carType==1&&b>0)
        {isPossible=true;
         --b;
        }
        if(carType==2&&m>0)
        {isPossible=true;
         --m;
        }
        if(carType==3&&s>0)
        {isPossible=true;
         --s;
        }
        return isPossible;
        
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */