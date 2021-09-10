#include <bits/stdc++.h>
using namespace std;
char Uppercase[26] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
char lowercase[26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};

void encrypt(string plaintext, int key);
void decrypt(string ciphertext, int key);


int main()
{
   char Choice;
   string plaintext;
   string ciphertext;
   int key;
   
     char choice;
	   cout << "[+] What you want to do encrypt or decrypt (E/D or e/d)?  ";  cin >> choice;
       
	   if (choice == 'E' || choice == 'e')
	    {
		   cout << "[+] Enter the plaintext below: "<<endl; 
		   cin.ignore();
		   getline(cin, plaintext);
		  // plaintext.erase(remove_if(plaintext.begin(), plaintext.end(), ::isspace), plaintext.end());
		   cout << "[+] Enter the key : "<<endl;  
		   cin >> key;
		   encrypt(plaintext, key);
		   plaintext = '\0';
		   cout << endl;
	    }
       else if(choice == 'D' || choice == 'd')
	   {
		   cout << "[+] Enter the ciphertext: "<<endl;  
		   cin.ignore();
		   getline(cin, ciphertext);
		   ciphertext.erase(remove_if(ciphertext.begin(), ciphertext.end(), ::isspace), ciphertext.end());
		   cout << "Enter the key : "<<endl;
		   cin >> key;
		   decrypt(ciphertext, key);
		   ciphertext = '\0';
		   cout << endl;
	   }
      
      
   return 0;
}

void encrypt(string plaintext, int key)
{
	char encrypt_text[plaintext.length()];
   
    
	for (int i = 0; i < plaintext.length(); i++)
	{   
		 
	if (plaintext[i] >= 65 && plaintext[i] <= 90)
	{
		for (int j = 0; j < 26; j++)
		{   
			
			if (plaintext[i] == Uppercase[j])
			{
				encrypt_text[i] = Uppercase[(j+key)% 26];
			    cout << encrypt_text[i];	
			}
			
		}
			
	}
	if (plaintext[i] >= 97 && plaintext[i] <= 122)
	{
       for (int k = 0; k < 26; k++)
	   {
		    if(plaintext[i] == lowercase[k])
		    {
			   encrypt_text[i] = lowercase[(k+key)% 26];
			   cout << encrypt_text[i];
			   
		    }
			
	   }
	}
    
	else if ((plaintext[i] < 97 && plaintext[i] > 122) && (plaintext[i] < 65 && plaintext[i] > 90))
	{
        cout <<"!!!! Plain text is invalid. Program will terminate\n";
		exit(0);
	}
	}	
}

void decrypt(string ciphertext, int key)
{

char decrypt[ciphertext.length()];
    
    
	for (int i = 0; i < ciphertext.length() ; i++)
	{   
		 
	if (ciphertext[i] >= 65 && ciphertext[i] <= 90)
	{
		for (int j = 0; j < 26; j++)
		{
			if (ciphertext[i] == Uppercase[j])
			{
				decrypt[i] = Uppercase[(j-key)% 26];
				cout << decrypt[i];	
			}
		}	
	}
	if (ciphertext[i] >= 97 && ciphertext[i] <= 122)
	{
       for (int k = 0; k < 26; k++)
	   {
		    if(ciphertext[i] == lowercase[k])
		    {
			  decrypt[i] = lowercase[(k-key)% 26];
			  cout << decrypt[i];
		    }
			
	   }
	}
    
	else if ((ciphertext[i] < 97 && ciphertext[i] > 122) && (ciphertext[i] < 65 && ciphertext[i] > 90))
	{
        cout <<"!!!! Cipher text is invalid. Program will terminate\n";
		exit(0);
	}
	}	
}