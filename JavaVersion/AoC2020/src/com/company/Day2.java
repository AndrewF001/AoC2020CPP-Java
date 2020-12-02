package com.company;


import java.util.ArrayList;

public class Day2 extends DefaultClass{

    public Day2()
    {
        super(2,true);
        ArrayList<String> inp = fr.ReadLine();
        ArrayList<String> passwords = new ArrayList<>();
        ArrayList<Integer> MinVal = new ArrayList<>();
        ArrayList<Integer> MaxVal = new ArrayList<>();
        ArrayList<Character> CharVal = new ArrayList<>();
        StringBuilder temp = new StringBuilder();
        for (int i = 0; i < inp.size(); i++) {
            for (int j = 0; j < inp.get(i).length(); j++) {
                if(inp.get(i).charAt(j)=='-') {
                    MinVal.add(Integer.parseInt(temp.toString()));
                    temp = new StringBuilder();
                }
                else if(inp.get(i).charAt(j)==':')
                {
                    MaxVal.add(Integer.parseInt(temp.substring(0,temp.length()-2)));
                    CharVal.add(temp.charAt(temp.length()-1));
                    temp = new StringBuilder();
                }
                else {
                    temp.append(inp.get(i).charAt(j));
                }
            }
            passwords.add(temp.substring(1,temp.length()));
            temp=new StringBuilder();
        }
        int sum=0;
        for (int i = 0; i < inp.size(); i++) {
            if(IsPassword(MinVal.get(i),MaxVal.get(i),CharVal.get(i),passwords.get(i)))
                sum++;
        }
        System.out.println("Part1: "+sum);
        sum=0;
        for (int i = 0; i < inp.size(); i++) {
            if(IsPasswordPart2(MinVal.get(i),MaxVal.get(i),CharVal.get(i),passwords.get(i)))
                sum++;
        }
        System.out.println("Part2: "+sum);
        TimeClock();
    }

    private boolean IsPassword(int min, int max, char C, String password)
    {
        int count=0;
        for (int i = 0; i < password.length(); i++) {
            if(password.charAt(i)==C)
                count++;
        }
        return(count>=min&&count<=max);
    }

    private boolean IsPasswordPart2(int pos1, int pos2, char C, String password)
    {
        if (password.charAt(pos1-1) == C ^ password.charAt(pos2-1) == C)
            return true;
        return false;

    }

}
