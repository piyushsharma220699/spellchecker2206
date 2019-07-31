//ALGORITHM PROJECT
//PIYUSH SHARMA (17103110)
//MEGHA SHARMA(17103101)
//VIKRAM (17103088)
//SPELL CHECKER

#include <bits/stdc++.h>
#include<iostream>
#include<cstring>
#include<fstream>
using namespace std;

const int total=26;

struct node
{
struct node* arr[total];

bool endofword;

};

struct node* makenewnode()
{
	struct node* newnode=new node;
	
	for(int i=0; i<total; i++)
	{
		newnode->arr[i]=NULL;
	}
	
	newnode->endofword=false;
	
	return newnode;
}



void insert(struct node *masterroot, string key)
{
	struct node* walker=masterroot;
	
	int n=key.length();
	
	for(int i=0; i<n; i++)
	{
		int index=key[i]-'a';
	
		if(!walker->arr[index])
		{
			walker->arr[index]= makenewnode();
		}
		
		walker=walker->arr[index];
		
	}
	
	walker->endofword=true;
}

bool search(struct node *masterroot, string key)
{
	struct node* walker=masterroot;
	
	int n=key.length();
	
	for(int i=0; i<n; i++)
	{
	    int index=key[i]-'a';
		
		if(!walker->arr[index])
			return false;
		
		else
		walker=walker->arr[index];
	}

 	if(walker->endofword==true)
      return true;

      return false; 
}	


int main()
{
	
    struct node* masterroot=makenewnode();
	
	string line;
	ifstream fin;
	fin.open("dictionary.txt");
	
	
	while(!fin.eof())
	{
	   getline(fin,line);
	   insert(masterroot,line);
	
	}
	
	fin.close();
	
	int i=1;
	string word;
	cout<<"\nWELCOME TO PIYUSH-MEGHA-VIKRAM SPELL CHECKER\n";
	
	while(i==1)
	{
		
	    cout<<"\nPlease Enter a Word to know if it exists in dictionary or not: \n\n";
	
	    string key;
	    cin>>key;
		
		transform(key.begin(), key.end(), key.begin(), ::tolower);
	
	    bool result;
	    result=search(masterroot,key);
	
	    if(result==true)
		{
			cout<<"\nYES! This Word Exists in Dictionary\n";
		}
		
		else
		{
			cout<<"\nThis result doesn't exists in Dictionary\n";
			int u=1;
			while(u)
			{
			cout<<"\nDo you want to add this result into the dictionary? \nIf Yes, Press (1) \nIf No, Press(2)\n";
			int s;
			cin>>s;
			if(s==1)
			{
				ofstream fout;
				fout.open("dictionary.txt",ios::app);
				fout<<"\n"<<key<<"\n";
				insert(masterroot, key);
				u=0;
			}
			else if(s==2)
				u=0;
			else
			    cout<<"\nPlease Enter a Valid Input! ENTER AGAIN\n";
			}
		}
	
	int x=1;
	while(x)
	{
		cout<<"\n\nDo You want to search a word or add some word in dictionary once more?\nIf Yes: Press (1) \nIf not: Press (2)\n\n";
		int ch;
		cin>>ch;
		if (ch==1)
			x=0;
		else if (ch==2)
		{
			x=0;
     	    i=0;
		}
		else
		cout<<"Please Enter a Valid Input! ENTER AGAIN \n\n";
	}
	
	}

}