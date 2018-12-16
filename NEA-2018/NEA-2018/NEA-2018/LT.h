#pragma once
#include "stdafx.h"
//спецификаци€ таблицы лексем
#define	LEXEMA_FIXSIZE   1	        //размер лексемы
#define	LT_MAXSIZE		 4096	    //максимальное количество строк в таблице лексем
#define	LT_TI_NULLDX	 0xffffffff	//нет элемента таблицы идентификаторов
#define LEX_SEPARATORS	     'S'
#define	LEX_ID_TYPE_I        'n'
#define	LEX_ID_TYPE_W        'q'
#define	LEX_ID_TYPE_B        'a'
#define	LEX_ID			     'i'			
#define	LEX_LITERAL		     'l'	
#define	LEX_FUNCTION         'f'
#define	LEX_IF               'd'
#define	LEX_ELSE             'e'
#define	LEX_START		     's'			
#define	LEX_RETURN		     'r'			
#define	LEX_OUT		         'o'	
#define LEX_CREATE           'c'
#define	LEX_SEPARATOR	     ';'
#define	LEX_DOLLAR           '$'
#define	LEX_COMMA		     ','			
#define	LEX_TO_OPEN_BLOCK	 '{'			
#define	LEX_TO_CLOSE_BLOCK	 '}'			
#define	LEX_LEFTHESIS	     '('			
#define	LEX_RIGHTTHESIS	     ')'
#define	LEX_PLUS		     '+'	
#define	LEX_MINUS		     '-'
#define LEX_STRCON		     'k'
#define LEX_LENGTH		     'b'
#define LEX_ISEMPTY		     'y'
#define	LEX_STAR		     '*'					
#define	LEX_EQUAL		     '='
#define	LEX_NOT		         '!'
#define	LEX_BIGGER           '>'
#define	LEX_LESS             '<'
#define	LEX_OPERATION	     'v'
#define LEX_LIB			     'z'
#define	LIT			      "literal"
#define	INTEGER			  "integer"		
#define	STRING			  "string"
#define	BOOLEAN			  "bool"
#define SPACE               ' '
#define point               '.'
namespace LT	//таблица лексем
{
	struct Entry                       //структура дл€ содержимого табл.лексем
	{
		char lexema;					//лексема
		int sn;							//номер строки в исходном тексте
		int idxTI;						//индекс в таблице идентификаторов или LT_TI_NULLIDX

		Entry();
		Entry(char lexema, int snn, int idxti = LT_TI_NULLDX);
	};

	struct LexTable						//экземпл€р таблицы лексем
	{
		int maxsize;					//Ємкость таблицы лексем
		int size;						//текущий размер таблицы лексем
		Entry* table;					//массив (Entity)строк таблицы лексем
	};

	LexTable Create(int size);		            //Ємкость < LT_MAXSIZE
	void Add(LexTable &lextable, Entry entry);	//экземпл€р таблицы лексем, строка таблицы лексем
}