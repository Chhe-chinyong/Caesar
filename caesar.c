#include<cs50.h>
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        exit(1);
    }
    else
    {
        string argv1 = argv[1];
        int a = 0;
        int length = strlen(argv[1]);
        for (int i = 0; i < length; i++)
        {
            if (isdigit(argv1[i]) == 0)
            {
                a = 1;
                break;
            }
        }

        if (a == 1)
        {
            printf("Usage: ./caesar key\n");
            exit(1);
        }

        // code your logic here
        else
        {
            int key = atoi(argv[1]);
            string text = get_string("Input your plaintext: ");
            int n = strlen(text);
            int index[n];
            for (int i = 0; i < n; i++)
            {
                if (isalpha(text[i]))
                {
                    if (isupper(text[i]))
                    {   
                        int store =  text[i] - 65;
                        if (store == 25)
                        {
                            index[i] = key - 1;
                        }
                        else
                        {   
                            index[i] = ((text[i] - 65) + key) % 26;
                        }
                    }
                    else if (islower(text[i]))
                    {
                        int store =  text[i] - 97;
                        if (store == 25)
                        {
                            index[i] = key - 1;
                        }
                        else
                        {
                            index[i] = ((text[i] - 97) + key) % 26;
                        }
                    }
                }
                else
                {

                    index[i] = text[i];
                }
            }
            int cipher[n];
            for (int j = 0; j < n; j++)
            {
                if (isupper(text[j]))
                {   
                    if (text[j] == 'Z')
                    {
                        cipher[j] = index[j] + 66;

                    }
                    else
                    {
                        cipher[j] = index[j] + 65;
                       
                    }
                }
                else if (islower(text[j]))
                {
                    if (text[j] == 'z')
                    {
                        cipher[j] = index[j] + 98;

                    }
                    else
                    {
                        cipher[j] = index[j] + 97;
                    }
                }
                else
                {
                    cipher[j] = index[j];
                }
            }
            
            printf("ciphertext: ");
            for (int z = 0; z < n; z++)
            {
                printf("%c", cipher[z]);
            }
            printf("\n");
        }
    }

}