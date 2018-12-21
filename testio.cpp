#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;

void subtest()
{
  
  fstream anotherfile("example.txt"); 
  
  if (anotherfile.is_open())
  {
    cout << "well thats weird" << endl ; 
  }
  else 
  {
    cout <<"tout roule" << endl ; 
  }
  anotherfile.close() ; 
  fstream myfile ("redirection.txt");
  if (myfile.is_open())
  {
    
    string line ; 
    while (!myfile.eof() )
    {
      getline (myfile,line);
      cout << line << endl ; 
    }
    
  }
  myfile.close();
}

int main()
{
  cout << "sortie standard"<<endl;
  fstream fic ("redirection.txt"); //fstream::app
  
  long pos =fic.tellg();
  cout<<pos<<endl;
  /*streambuf*oldStreamBuffer=cout.rdbuf(fic.rdbuf());
  cout<<"124"<<endl;
  cout.rdbuf(oldStreamBuffer);
  cout << "sortie standard"<<endl;*/
  string s ; 
  //char* s = new char [8];
  fic.seekg(0);
  pos =fic.tellg();
  cout<<pos<<endl;
  getline(fic, s);
  cout<<s<<endl;
  
  cout<<"a nouveau sur stdo"<<endl;
  fic.close(); 
 /* cout << "INPUT : " ; 
  char input[100];
  cin.getline(input,sizeof(input),'w');
  cout << input << endl ; */
  
  subtest() ; 
}
