package com.company;

import java.sql.Time;
import java.util.ArrayList;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class Day4 extends DefaultClass{

    public Day4()
    {
        super(4,true);
        ArrayList<String> inp = fr.ReadLine();
        ArrayList<String> Data = new ArrayList();
        StringBuilder temp=new StringBuilder();
        ResetClock();
        for (int i = 0; i < inp.size(); i++) {
            if(inp.get(i).equals(""))
            {
                Data.add(temp.toString());
                temp = new StringBuilder();
            }
            else
            {
                temp.append(inp.get(i)+" ");
            }
        }
        Data.add(temp.toString());
        int sum=0;
        for (int i = 0; i < Data.size(); i++) {
            if(Data.get(i).contains("byr")&&Data.get(i).contains("iyr")&&Data.get(i).contains("eyr")&&Data.get(i).contains("hgt")&&Data.get(i).contains("hcl")
                    &&Data.get(i).contains("ecl")&&Data.get(i).contains("pid"))
                sum++;
        }
        System.out.println("Part1: "+sum);
        TimeClock();
        ResetClock();
        System.out.println("Part2: "+ part2(Data));
        TimeClock();
    }

    private int part2(ArrayList<String> inp)
    {
        int sum=0;
        for (int i = 0; i < inp.size(); i++) {
            Data x = new Data();
            x.InputString(inp.get(i));
            if (x.Valid())
                sum++;
        }
        return sum;
    }

    private class Data
    {
        public String byr="", iyr="", eyr="", hgt="", hcl="", ecl="", pid="", cid="";

        public void InputString(String str)
        {
            String[] sep = str.split(" ");
            for (int i = 0; i < sep.length; i++) {
                if(sep[i].contains("byr"))
                {
                    String[] sep2 = sep[i].split(":");
                    byr = sep2[1];
                }
                else if(sep[i].contains("iyr"))
                {
                    String[] sep2 = sep[i].split(":");
                    iyr = sep2[1];
                }
                else if(sep[i].contains("eyr"))
                {
                    String[] sep2 = sep[i].split(":");
                    eyr = sep2[1];
                }
                else if(sep[i].contains("hgt"))
                {
                    String[] sep2 = sep[i].split(":");
                    hgt = sep2[1];
                }
                else if(sep[i].contains("hcl"))
                {
                    String[] sep2 = sep[i].split(":");
                    hcl = sep2[1];
                }
                else if(sep[i].contains("ecl"))
                {
                    String[] sep2 = sep[i].split(":");
                    ecl = sep2[1];
                }
                else if(sep[i].contains("pid"))
                {
                    String[] sep2 = sep[i].split(":");
                    pid = sep2[1];
                }
            }

        }

        public boolean Valid()
        {
            return ValidBYR()&&ValidECL()&&ValidEYR()&&ValidHCL()&&ValidIRY()&&ValidPID()&&ValidHGT();
        }

        private boolean ValidBYR()
        {
            try {
                return ((Integer.parseInt(byr) >= 1920 && Integer.parseInt(byr) <= 2002));
            }
            catch (Exception e)
            {
                return false;
            }
        }

        private boolean ValidIRY()
        {
            try {
                return (Integer.parseInt(iyr) >= 2010 && Integer.parseInt(iyr) <= 2020);
            }
            catch (Exception e)
            {
                return false;
            }
        }

        private boolean ValidEYR()
        {
            try {
                return (Integer.parseInt(eyr) >= 2020 && Integer.parseInt(eyr) <= 2030);
            }
            catch (Exception e) {
                return false;
            }
        }
        private boolean ValidHGT()
        {
            try {
                int hg = Integer.parseInt(hgt.substring(0, hgt.length() - 2));
                String cm = hgt.substring(hgt.length() - 2, hgt.length());
                if (cm.equals("cm")) {
                    if (hg >= 150 && hg <= 193)
                        return true;
                    else
                        return false;
                } else if (cm.equals("in")) {
                    if (hg >= 59 && hg <= 76)
                        return true;
                    else
                        return false;
                }
                return false;
            }
            catch (Exception e)
            {
                return false;
            }
        }

        private boolean ValidHCL()
        {
            try {
                if (hcl.charAt(0) == '#') {
                    return isHexadecimal(hcl.substring(1));
                }
            }
            catch (Exception e)
            {
                return false;
            }
            return  false;
        }

        private boolean ValidECL()
        {
            if(ecl.equals("amb")||ecl.equals("blu")||ecl.equals("gry")||ecl.equals("brn")||ecl.equals("grn")||ecl.equals("hzl")||ecl.equals("oth"))
                return true;
            else
                return false;
        }

        private boolean ValidPID()
        {
            if(pid.length()==9)
            {
                try
                {
                    Integer.parseInt(pid);
                    return true;
                }
                catch (Exception e)
                {
                    return false;
                }
            }
            return false;
        }
    }

    private static final Pattern HEXADECIMAL_PATTERN = Pattern.compile("\\p{XDigit}+");

    private boolean isHexadecimal(String input) {
        final Matcher matcher = HEXADECIMAL_PATTERN.matcher(input);
        return matcher.matches();
    }

}
