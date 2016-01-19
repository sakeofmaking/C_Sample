/**********************************************************************
 * Title: Linked List Paragraph
 *
 * Author: Nic La
 *
 * Purpose: Write a program that divides up some input text into sentences 
 * and then determines which sentence in the input has the most words. Print 
 * out the sentence with the most words and the number of words that are in it. 
 * Optionally, also print out all words in that sentence that are longer than 4 characters.
 * Sentences can end in periods, exclamation points and question marks, but not colons or semi-colons.
 *
 * If you need something to input, try Shylock's famous speech from Shakespeare's The Merchant of Venice:
 * If it will feed nothing else, it will feed my revenge. He hath disgrac'd me and hind'red me half a million; laugh'd at my losses, mock'd at my gains, scorned my nation, thwarted my bargains, cooled my friends, heated mine enemies. And what's his reason? I am a Jew. Hath not a Jew eyes? Hath not a Jew hands, organs, dimensions, senses, affections, passions, fed with the same food, hurt with the same weapons, subject to the same diseases, healed by the same means, warmed and cooled by the same winter and summer, as a Christian is? If you prick us, do we not bleed? If you tickle us, do we not laugh? If you poison us, do we not die? And if you wrong us, shall we not revenge? If we are like you in the rest, we will resemble you in that. If a Jew wrong a Christian, what is his humility? Revenge. If a Christian wrong a Jew, what should his sufferance be by Christian example? Why, revenge. The villainy you teach me I will execute; and it shall go hard but I will better the instruction.
 *
 * Prompt: https://www.reddit.com/r/dailyprogrammer/comments/srowj/4252012_challenge_44_easy/
 *
 * Requirements:
 * Divide paragraph into sentences
 *      Sentences can end in '.', '?', '!'
 * Count how many words are in each sentence
 *      Words can be identified by ' '
 * Print the sentence with the most words and number of words in it.
 *
 **********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct linked_list
{
    int word_count;
    char data[500];
    struct linked_list *next_ptr;
};

struct linked_list *first_ptr = NULL;
struct linked_list *curr = NULL;

struct linked_list *create_list(char *item)
{
    struct linked_list *ptr;
    ptr = malloc(sizeof(struct linked_list));
    
    if(NULL == ptr)
    {
        printf("\n Node creation failed \n");
        return NULL;
    }
    strcpy(ptr->data, item);
    ptr->next_ptr = NULL;
    
    first_ptr = curr = ptr;
    
    return ptr;
}

struct linked_list *add_to_list(char *item)
{
    if(NULL == first_ptr)
    {
        return (create_list(item));
    }
    
    struct linked_list *ptr;
    ptr = malloc(sizeof(struct linked_list));
    
    if(NULL == ptr)
    {
        printf("\n Node creation failed \n");
        return NULL;
    }
    strcpy(ptr->data, item);
    ptr->next_ptr = NULL;
    
    curr->next_ptr = ptr;
    curr = ptr;
    
    return ptr;
}

// For DEBUG
void print_list(void)
{
    struct linked_list *ptr = first_ptr;
    
    printf("\n -------Printing list Start------- \n");
    while(ptr != NULL)
    {
        printf("\n [%s] %d \n",ptr->data, ptr->word_count);
        ptr = ptr->next_ptr;
    }
    printf("\n -------Printing list End------- \n");
    
    return;
}

int main(void)
{
    char paragraph[] = "If it will feed nothing else, it will feed my revenge. He hath disgrac'd me and hind'red me half a million; laugh'd at my losses, mock'd at my gains, scorned my nation, thwarted my bargains, cooled my friends, heated mine enemies. And what's his reason? I am a Jew. Hath not a Jew eyes? Hath not a Jew hands, organs, dimensions, senses, affections, passions, fed with the same food, hurt with the same weapons, subject to the same diseases, healed by the same means, warmed and cooled by the same winter and summer, as a Christian is? If you prick us, do we not bleed? If you tickle us, do we not laugh? If you poison us, do we not die? And if you wrong us, shall we not revenge? If we are like you in the rest, we will resemble you in that. If a Jew wrong a Christian, what is his humility? Revenge. If a Christian wrong a Jew, what should his sufferance be by Christian example? Why, revenge. The villainy you teach me I will execute; and it shall go hard but I will better the instruction.";
    char sentence[500];
    char *paragraph_ptr = paragraph;
    int index = 0;
    int i;
    
    /****** Divide paragraph into sentence ******/
    // Use linked list
    while(*paragraph_ptr != '\0')
    {
        index = 0;
        while((*paragraph_ptr != '.')&&(*paragraph_ptr != '?')&&(*paragraph_ptr != '!'))
        {
            sentence[index] = *paragraph_ptr;
            index++;
            paragraph_ptr++;
        }
        sentence[index] = *paragraph_ptr;
        index++;
        paragraph_ptr++;
        if(*paragraph_ptr == ' ')
        {
            paragraph_ptr++;
        }
        sentence[index] = '\0';
    
        add_to_list(sentence);
    }
    
    /****** Count words in each sentence ******/
    struct linked_list *ptr = first_ptr;
    int most_words = 0;
    while(ptr != NULL)
    {
        ptr->word_count = 1;
        for(i = 0; i < strlen(ptr->data); i++)
        {
            if((ptr->data[i]) == ' ')
            {
                (ptr->word_count)++;
            }
        }
        if((ptr->word_count) > most_words)
        {
            most_words = ptr->word_count;
            strcpy(sentence, ptr->data);
        }
        ptr = ptr->next_ptr;
    }
    
    /****** Display sentence with the most word ******/
    printf("[%s] %d\n", sentence, most_words);
    
    return 0;
}


















