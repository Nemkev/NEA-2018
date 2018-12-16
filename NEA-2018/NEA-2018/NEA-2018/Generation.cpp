#include "stdafx.h"
#include "Generation.h"

ofstream fout("Out.html");
void Head()
{
	fout << "<html>" << endl;
	fout << "<head>" << endl;
	fout << "<title>" << endl;
	fout << "NEA-2018" << endl;
	fout << "</title>" << endl;
	fout << "<link rel=\"stylesheet\" type=\"text/css\" media=\"screen\" href=\"main.css\">" << endl;
	fout << "</head>" << endl;
	fout << "<body>" << endl;
	fout << "<header>" << endl;
	fout << "</header>" << endl;
	fout << "<main>" << endl;
	fout << "<script>" << endl << endl;
}
void Down()
{
	fout << "</script>" << endl;
	fout << "</main>" << endl;
	fout << "<footer>" << endl;
	fout << "</footer>" << endl;
	fout << "</body>" << endl;
	fout << "</html>" << endl;
	fout.close();
}



void Generation(LT::LexTable &Lextable, In::StToken *tokens)
{
	Head();
	char * concat = "function concat(str0,str1,str2){return str0 = str1+str2;};\n";
	fout << concat;
	for (int i = 0; i < Lextable.size; i++)
	{
		switch (Lextable.table[i].lexema)
		{
		case LEX_PLUS:
		case LEX_STAR:
		case LEX_MINUS:
		case  LEX_EQUAL:
		case LEX_BIGGER:
		case LEX_LESS:
		case LEX_NOT:
		{
			fout << " " << Lextable.table[i].lexema << " ";
			break;
		}
		case LEX_COMMA:
		case SPACE:
		{
			fout << Lextable.table[i].lexema << " ";
			break;
		}

		case LEX_DOLLAR: {
			Lextable.table[i].lexema = '=';
			fout << " " << Lextable.table[i].lexema;
		}

		case LEX_RIGHTTHESIS:
		case LEX_LEFTHESIS:
		{
			fout << Lextable.table[i].lexema;
			break;
		}
		case LEX_TO_OPEN_BLOCK:
		{

			fout << endl << Lextable.table[i].lexema << endl;
			break;
		}
		case LEX_TO_CLOSE_BLOCK:
		{

			fout << Lextable.table[i].lexema << endl << endl;
			break;
		}
		case LEX_SEPARATOR:
		{
			fout << Lextable.table[i].lexema << endl;
			break;
		}
		case  LEX_CREATE:
		{
			fout << "let ";
			break;
		}
		case LEX_LITERAL:
		case LEX_ID:
		{
			fout << tokens[i].token;
			break;
		}
		case LEX_OUT:
		{
			fout << "document.write" << endl;
			break;
		}

		case LEX_IF:
		{
			fout << "if" << endl;
			break;
		}
		case LEX_ELSE:
		{
			fout << "else" << endl;
			break;
		}
		case point:
		{
			fout << endl;
			break;
		}
		case LEX_FUNCTION:
		{
			fout << "function ";
			break;
		}
		case LEX_RETURN:
		{
			fout << "return ";
			break;
		}

		case LEX_STRCON:
		{
			fout << tokens[i + 2].token << " = concat";
			break;
		}
		case LEX_LENGTH:
		{
			fout << tokens[i + 2].token << ".length";
			i += 3;
			break;
		}

		case LEX_ISEMPTY:
		{
			char * isEmpty = "function isEmpty(str){if(!str) return true; return false;}";
			fout << "isEmpty(" << tokens[i + 2].token << ");" << isEmpty;
			i += 3;
			break;
		}
		}
	}
	Down();

}

