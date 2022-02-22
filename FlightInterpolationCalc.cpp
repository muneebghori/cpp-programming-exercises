#include <iostream>
#include <string>
#include <cmath>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <ios>
#include <iomanip>

using namespace std;

void readData(const string&, vector<double>&, vector<double>&);
double interpolation(double, const vector<double>&, const vector<double>&);
bool isOrdered(const vector<double>&);
void reorder(vector<double>&, vector<double>&);

int main()
{
   string userInputFile;
   vector<double> path;
   vector<double> lift;
   bool validInput = true;
   double pathInput;
   double liftCoefficient;

   cout << "Enter name of input data file:" << endl << endl;
   cin >> userInputFile;

   readData(userInputFile, path, lift);

   cout << endl << endl;

   if(path.empty())
   {
       while(path.empty() || (path.size() != lift.size()))
       {
           cout << "Enter a different file" << endl;
           cin >> userInputFile;
           readData(userInputFile, path, lift);
       }
   }
   while(!isOrdered(path))
   {
       reorder(path, lift);
   }

   while(validInput)
   {
       cout << "Enter flight path angle" << endl << "Enter 1337 to break the loop and exit" << endl;
       cout << "Do not enter a string value, only doubles or ints" << endl << endl;
       cin >> pathInput;
       if(pathInput == 1337)
       {
           validInput = false;
       }
       else if(pathInput < path.at(0) || pathInput > path.at(path.size() - 1))
       {
           cout << "Enter a value in the data's range" << endl;
           cin >> pathInput;
       }
       else
       {
           liftCoefficient = interpolation(pathInput, path, lift);
           cout << "The lift coefficient for the flight path angle " << pathInput << " is: " << liftCoefficient << endl;
       }
   }

   return 0;
}

void readData(const string& fileInput, vector<double>& path, vector<double>& lift)
{
   ifstream dataFile;
   double temp1 = 0.0;
   double temp2 = 0.0;

   dataFile.open(fileInput.c_str());

   if(!dataFile.is_open())
   {
       cout << "Error opening " << fileInput << endl;
       exit(1);
   }
   while(dataFile >> temp1)
   {
       path.push_back(temp1); //dataFile takes in temp1 then pushes into path vector
       dataFile >> temp2;
       lift.push_back(temp2); //start reading again after whitespace, then push into lift
   }

   dataFile.close();
}

double interpolation(double b, const vector<double>& path, const vector<double>& lift)
{
   for(unsigned i = 0; i < path.size(); i++)
   {
       if(path.at(i) == b)
       {
           return lift.at(i);
       }
   }
   for(unsigned i = 0; i < path.size(); i++)
   {
       if(b > path.at(i))
       {
           return lift.at(i) + (b - path.at(i)) / (path.at(i+1) - path.at(i)) * (lift.at(i+1) - lift.at(i));
       }
   }
   return 0;
} //f(b) = f(a) + (b - a)/(c - a)(f(c) - f(a))

bool isOrdered(const vector<double>& path)
{
   if(!path.empty())
   {
       for(unsigned i = 0; i+1 < path.size(); i++)
       {
           if(path.at(i) > path.at(i+1))
           {
               return false;
           }
       }
   }
   return true;
}

unsigned findMin(const vector<double>& v, unsigned start)
{
   unsigned small = start;
   for(unsigned i = start + 1; i < v.size(); i++)
   {
       if(v.at(i) < v.at(small))
       {
           small = i;
       }
   }
   return small;
}

void reorder(vector<double> &path, vector<double> &lift)
{
    sort(path.begin(), path.end());
    sort(lift.begin(), lift.end());
}

