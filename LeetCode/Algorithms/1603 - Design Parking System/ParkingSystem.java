// ==================================================
// Problem  :   1603 - Design Parking System 
// Run time :   0.006 sec
// Language :   Java
// ==================================================

public class ParkingSystem {
    int bigSlotRem;
    int mediumSlotRem;
    int smallSlotRem;
    
    public ParkingSystem(int big, int medium, int small) {
        this.bigSlotRem = big;
        this.mediumSlotRem = medium;
        this.smallSlotRem = small;
    }
    
    public boolean addCar(int carType) {
        boolean isAdded = false;
        
        if (carType == 1) {
            if (bigSlotRem > 0) {
                --bigSlotRem;
                isAdded = true;
            }
        } else if (carType == 2) {
            if (mediumSlotRem > 0) {
                --mediumSlotRem;
                isAdded = true;
            }
        } else {
            if (smallSlotRem > 0) {
                --smallSlotRem;
                isAdded = true;
            }
        }
        
        return isAdded;
    }
}
