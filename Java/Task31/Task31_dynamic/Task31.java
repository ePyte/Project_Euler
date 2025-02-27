package Task31_dynamic;

import java.util.ArrayList;
import java.util.List;

public class Task31{

    public static int[] coins = {1, 2, 5, 10, 20, 50, 100, 200};
    public static int value = 200;

    public static int DifferentWays()
    {
        int[] workingArray = new int[value+1];
        workingArray[0] = 1;

        for(int i = 0; i< coins.length; i++){
            int coinVal = coins[i];
            for(int j = coinVal; j<workingArray.length; j++){
                workingArray[j] += workingArray[j-coinVal];
            }
        }
        
        return workingArray[value];
    }



    public static void main(String[] args){
        System.out.println("?");
        System.out.println(DifferentWays());

    }
    
}


