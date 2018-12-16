#pragma once
#include "stdafx.h"
//������������ ������� ������
#define	LEXEMA_FIXSIZE   1	        //������ �������
#define	LT_MAXSIZE		 4096	    //������������ ���������� ����� � ������� ������
#define	LT_TI_NULLDX	 0xffffffff	//��� �������� ������� ���������������
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
namespace LT	//������� ������
{
	struct Entry                       //��������� ��� ����������� ����.������
	{
		char lexema;					//�������
		int sn;							//����� ������ � �������� ������
		int idxTI;						//������ � ������� ��������������� ��� LT_TI_NULLIDX

		Entry();
		Entry(char lexema, int snn, int idxti = LT_TI_NULLDX);
	};

	struct LexTable						//��������� ������� ������
	{
		int maxsize;					//������� ������� ������
		int size;						//������� ������ ������� ������
		Entry* table;					//������ (Entity)����� ������� ������
	};

	LexTable Create(int size);		            //������� < LT_MAXSIZE
	void Add(LexTable &lextable, Entry entry);	//��������� ������� ������, ������ ������� ������
}