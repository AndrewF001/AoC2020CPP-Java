package com.company;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;

public class FileReader {

    public String FileName;
    File file;
    Scanner scn;

    public FileReader(String FileName)
    {
        this.FileName = FileName;
        file = new File(this.FileName);
        try {
            scn = new Scanner(file);
        }
        catch (FileNotFoundException e) {
            e.printStackTrace();
        }
    }

    public String ReadStraight()
    {
        String str="";
        while(scn.hasNextLine())
            str+=scn.nextLine();
        return str;
    }

    public ArrayList<String>ReadLine()
    {
        ArrayList<String> str = new ArrayList<>();
        while (scn.hasNextLine())
            str.add(scn.nextLine());
        return str;
    }

    public ArrayList<Integer>ReadInts()
    {
        ArrayList<Integer> integers = new ArrayList<>();
        ArrayList<String> str = ReadLine();
        for (String x:str) {
            integers.add(Integer.parseInt(x));
        }
        return integers;
    }

    public ArrayList<Integer>ReadInts(ArrayList<String> str)
    {
        ArrayList<Integer> integers = new ArrayList<>();
        for (String x:str) {
            integers.add(Integer.parseInt(x));
        }
        return integers;
    }

    public ArrayList<String> SplitString()
    {
        String str = ReadStraight();
        String[] out = str.split(",");
        ArrayList<String> list = new ArrayList<String>(Arrays.asList(out));
        return list;
    }

    public ArrayList<String> SplitString(String str)
    {
        String[] out = str.split(",");
        ArrayList<String> list = new ArrayList<String>(Arrays.asList(out));
        return list;
    }

    public static void PrintFiles()
    {
        File file = new File(".");
        for(String fileNames : file.list()) System.out.println(fileNames);
    }

}
