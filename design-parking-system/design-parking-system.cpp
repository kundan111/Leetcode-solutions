class ParkingSystem {
public:
    int b,m,s;
    ParkingSystem(int big, int medium, int small) {
        b = big;
        m = medium;
        s = small;
    }
    
    bool addCar(int carType) {
        if(carType == 1)
        {
            if(b >= 1)
            {
                b--;
                return true;
            }
            
            return false;
        }else if(carType == 2)
        {
            if(m >= 1)
            {
                m--;
                return true;
            }
            return false;

        }else{
            if(s >= 1)
            {
                s--;
                return true;
            }
            return false;

        }
    }
};