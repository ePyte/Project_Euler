//very slow solution: works with "normal" time frame until ~20
package Task31_recursion;

import java.util.ArrayList;
import java.util.Collection;
import java.util.Collections;
import java.util.List;

public class Task31{

    public static int[] coins = {1, 2, 5, 10, 20, 50, 100, 200};
    public static List<Integer> coinList = new ArrayList<>();
    public static int upperLimit = 20;
    public static List<Integer> currentList = new ArrayList<>();
    public static List<List<Integer>> finalList = new ArrayList<>();

    public static void initCoinList(){
        for (int i = coins.length-1; i>=0; i--){
            coinList.add(coins[i]);
        }
    }

    public static int SumCoinValues(List<Integer> list){
        int sum = 0;
        for(int element : list){
            sum += element;
        }
        return sum;
    }

    public static boolean containFunc(List<Integer> list){
        for(int i = 0; i < finalList.size(); i++){
            if(finalList.get(i).size() == list.size()){
                List<Integer> listCopy = new ArrayList<>(finalList.get(i));
                for(int j = 0; j<list.size(); j++){
                    if(listCopy.contains(list.get(j))){
                        listCopy.remove(list.get(j));
                    }
                }
                if(listCopy.size()==0){
                    return true;
                }
            }
        }
        return false;
    }

    public static void DifferentWays()
    {
        if(SumCoinValues(currentList) > upperLimit){
            return;
        }

        if(SumCoinValues(currentList) == upperLimit){
            if(!containFunc(currentList)){
                finalList.add(new ArrayList<>(currentList));
                return;
            }
        }


        for(int coin : coinList){
            if(currentList.isEmpty() || coin <= currentList.get(currentList.size()-1)){

                currentList.add(coin);

                for(int i = 0; i < currentList.size(); ++i){
                        System.out.println(currentList.get(i));
                    }
                    System.out.println("");

                DifferentWays();
                currentList.remove(currentList.size()-1);
            }   
        }
    }

    public static void main(String[] args){
        initCoinList();
        DifferentWays();
        for(int i = 0; i < finalList.size(); ++i){
            for(int j = 0; j <finalList.get(i).size(); ++j){
                System.out.println(finalList.get(i).get(j));
            }
            System.out.println("");
        }
        System.out.println(finalList.size());
    }
}


