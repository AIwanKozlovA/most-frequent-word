#include <iostream>
#include <string>
#include <vector>
using namespace std;
vector<string> map(string text);
int count_p(string text);
bool in_massiv(vector<string>  slows, string slow,int ras);
int nom_el(vector<string>  slows, string slow,int ras);
int nom_el_max(vector<int>  kol,int ras);
string uppercase(string text);
int main(){
  string text , ass="1111!;.";
  //getline(cin,text);

  text="ff ff ff, vv! vv? Vv ghh: Vv hh vv. vv; vv";
  //strcat_s(text, " ");
  text=uppercase(text);
  text=text+" ";
  vector<string> slows=map(text),slowa;
  vector<int> kol;
  int count=count_p(text),cl=0,nm;
  //cout<<in_massiv(slows,"vv",count)<<endl;
  for(int i=0;i<count+2;i++){
    if (cl == 0 || in_massiv(slowa,slows[i],cl) == 0){
      slowa.push_back(slows[i]);
      kol.push_back(1);
      cl++;
    }else{
      kol[nom_el(slowa,slows[i],cl)]++;
    }
  }
  nm=nom_el_max(kol,cl);
  cout<<slows[8]<<endl;
  cout<<slows[9]<<endl;
  cout<<slows[10]<<endl;
  cout<<"Самое частое слово: "<<slowa[nm]<<" оно встречается в тексте "<<kol[nm]<<" раз"<<endl;
  return 0;
}
vector<string> map(string text){
  int ras=text.length();
  string sl;
  vector<string> slows;
  for(int i=0;i<ras+2;i++){
    if (text[i]==' ' || i == ras+1 || text[i] == ',' || text[i] == '.' || text[i] == ':' || text[i] == '!' || text[i] == '?' || text[i] == ';'){
      if (sl != ""){
        slows.push_back(sl);
        sl="";
      }
    }else{
      sl+=text[i];
    }
  }
  return slows;
}
int count_p(string text){
  int ras=text.length();
  int cs=0;
  for(int i=0;i<ras+2;i++){
    if ((text[i]==' ' && text[i-1] !='!' && text[i-1] !=',' && text[i-1] !='.' && text[i-1] !=':' && text[i-1] !='?' && text[i-1] !=';') || i == ras+1 || text[i] == ',' || text[i] == '.' || text[i] == ':' || text[i] == '!' || text[i] == '?' || text[i] == ';'){
      cs++;
    }
  }
  return cs;
}
bool in_massiv(vector<string>  slows, string slow,int ras){
  for (int i=0;i<ras;i++){
    if(slow == slows[i]){
      return true;
    }
  }
  return false;
}
int nom_el(vector<string>  slows, string slow,int ras){
  for (int i=0;i<ras;i++){
    if(slow == slows[i]){
      return i;
    }
  }
  return 0;
}
int nom_el_max(vector<int>  kol,int ras){
  int max,nom;
  for (int i=0;i<ras;i++){
    if(kol[i]>max){
      max=kol[i];
      nom=i;
    }
  }
  return nom;
}
string uppercase(string text){
  string temp="";
  int i=0,k=text.length();
  while(i<k)
    {
      temp+=tolower(text[i]);
       i++;
    }
    return temp;
}
