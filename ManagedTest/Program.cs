using System;

using ManagedCppQtSpace;


namespace ManagedTest
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Creating object!");
            ManagedCppQt mcq = new ManagedCppQt("test");
            Console.WriteLine("Adding eventhandler!");
            //mcq.someFuncCalled += (str) => Console.WriteLine("I were called: "+ str);
            Console.WriteLine("Calling someFunc!");
            mcq.someFunc("here look I'm calling someFunc!");
            Console.WriteLine(mcq.getSomeString());
        }
    }
}
