#include<iostream>
#include<string>
#include<sstream>
#include<vector>
#include<time.h>
using namespace std;
string number[4536];

void find(string input,int bulls,int cows)
{
	for(int i=0;i<4536;i++)
	{
		if(number[i] != "-1")
		{
			string temp = number[i];
			int b=0,c=0;
			for(int i = 0; i < 4; i++ )
			{
				if( input[i] == temp[i] )
					 b++;
				else
				{
					for(int j = 0; j < 4; j++ )
						if( input[i] == temp[j] )
							 c++;
				}
			}
			if(b != bulls || c != cows)
			{
				number[i] = "-1";
			}
		}
	}
}

string random_num()
{
	vector<string> vec;
        for(int j=0;j<4536;j++)
        {
		if(number[j] != "-1")
		{
		    
		    vec.push_back(number[j]);
		}
        }
        string generate;
        srand( time(NULL) );
        generate = vec[rand() % vec.size()];
        for(int i=0;i<4536;i++)
        {
	    	if(number[i] == generate)
	    	{
	    		number[i] = "-1";
	    	}
        }
        return generate;
}


int main()
{
	int count=0,toss, id;
	string guess;
  
	for(int i = 1; i <= 9; i++)
	{
		for(int j=0;j<=9;j++)
		{
			for(int z=0;z<=9;z++)
			{
				for(int h=0;h<=9;h++)
				{
					if(i != j && i != z && i != h && j != z && j != h &&  z != h)
					{
						int p = 1000*i + 100*j + 10*z + 1*h;
						ostringstream s1;
						s1<<p;
						string s2 = s1.str();
                        number[count] = s2;
                        count++;
					}
				}
			}
		}
	}
    srand( time(NULL) );
    guess = number[rand() % 4536];
    cin >> id;
    cout<<guess<<endl;
    cin>>toss;
    if(toss == 0)
    {
        while(true)
        {
            string opponent_guess;
            int opponent_bulls=0,opponent_cows=0;
      
            cin>>opponent_guess;        
            for(int i = 0; i < 4; i++ )
            {
                if( guess[i] == opponent_guess[i] ) opponent_bulls++;
                else
                {
                    for(int j = 0; j < 4; j++ )
                    if( guess[i] == opponent_guess[j] )
                    {       
                        opponent_cows++;
                        break;
                    }   
                }
            }
         
            cout<<opponent_bulls<<endl;
            cout<<opponent_cows<<endl;            
       
            string s = random_num();
            int bulls=0,cows=0;
     	    cout<<s<<endl;
            cin>>bulls>>cows;
            find(s,bulls,cows);
	}
    }  
    if(toss == 1)
    {
        while(true)
        {
           
            string s = random_num();
            int bulls=0,cows=0,opponent_bulls=0,opponent_cows=0;
            string opponent_guess;
      
            cout<<s<<endl;
   
            cin>>bulls>>cows;
           
            find(s,bulls,cows);
        
            cin>>opponent_guess;        
            for(int i = 0; i < 4; i++ )
            {
                if( guess[i] == opponent_guess[i] ) opponent_bulls++;
                else
                {
                    for(int j = 0; j < 4; j++ )
                    if( guess[i] == opponent_guess[j] )
                    {
                        opponent_cows++;
                        break;
                    }
                }
            }
        
            cout<<opponent_bulls<<endl;
            cout<<opponent_cows<<endl;
           
        }
    }    
           
}
