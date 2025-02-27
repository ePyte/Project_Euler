package Task32;

import java.util.*;

public class Task32Solution{
    public static int startNumber = 1;
    public static int endNumber = 9999;
    public static List<Integer> resultsList = new ArrayList<>();
    public static int numOfDiffDigits = 9;
    public static List<Integer> digitsList = new ArrayList<>();
    
    public static boolean checkForLastDigit(int i){
        if((i % 10 == 0) || (i % 10 == 1) || (i % 10 == 5)){
            return true;
        }
        return false;
    }

    public static int calculateDigitsNumber(int i){
        int sum = 1; //all numbers are at least 1 digit long
        while(i / 10 > 0){
            i /=10;
            sum++;
        }
        return sum;
    }

    public static int checkForLengths(int multicand, int multipland, int product){
        int sumOfDigits = 0;
        sumOfDigits+= (calculateDigitsNumber(multicand) + calculateDigitsNumber(multipland) + calculateDigitsNumber(product));
        return sumOfDigits;
    }

    public static void getDigits(int number){
        int nextDigit = 0;
        while(number != 0){
            nextDigit = number % 10;
            digitsList.add(nextDigit);
            number /= 10; 
        }
    }

    private static boolean checkDigitsInOrder() {
        for(int i = 0; i < digitsList.size(); i++){
            if(i+1 != digitsList.get(i)){
                return false;
            }
        }
        return true;
    }

    public static void checkPan(int multicand, int multipland, int product){
        getDigits(multicand);
        getDigits(multipland);
        getDigits(product);
        Collections.sort(digitsList);
        if (checkDigitsInOrder() && !resultsList.contains(product)){
            resultsList.add(product);
        }
        digitsList = new ArrayList<>();
    }

    private static void iterateFunc() {
        //min.1 digit * min.4 digits = min.4 digits -> 9 digits
        for(int i = startNumber; i<=endNumber; i++){
            if(checkForLastDigit(i)){
                continue;
            }
            for(int j = i+1; j<=endNumber; j++){
                if(checkForLastDigit(i)){
                    continue;
                }
                int product = i*j;
                if(checkForLengths(i, j, product) < 9){
                    continue;
                }
                if(checkForLengths(i, j, product) == 9){
                    checkPan(i, j, product);
                }
                else{
                    break;
                }
            }
        }
    }

    public static int sumOfListElements(){
        int sum = 0;
        for (int number : resultsList) {
            //System.out.println(number);
            sum += number;
        }
        return sum;
    }

    public static void main(String[] args) {
        iterateFunc();
        System.out.println(sumOfListElements());
    }
}

/*
*checkForLastDigit() function:
 * multicand or multipland ends with:
 * -> 0 -> duplication: e.g.: xx0 * yyy = zzz0
 * -> 1 -> duplication: e.g.: xx1 * yy2 = zzz2
 * -> 5 -> : e.g.: xx5 * yyy = zzz0 or zzz5: 0 is invalid digit; 5 is duplication
 *
 *
 *
 */