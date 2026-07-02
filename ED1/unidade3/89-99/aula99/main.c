#include <stdio.h>
#include "spellbook.h"

int main(){
    Spellbook *book;
    book=create_spellbook();
    add_spell(book,1,"Bola de Fogo",30);
    add_spell(book,2,"Gelo Supremo",40);
    add_spell(book,3,"Raio Arcano",25);
    display_spellbook(book);
    destroy_spellbook(book);
    return 0;
}