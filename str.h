/*
 Author: man_s_our
 this header was made in purpose of having a crossplatform
 functions that doesn't need installing any library.
*/
void copy(char* src, char* dst, int size)
{
	int i;
	for(i = 0; i < size; i++)
	{
		dst[i] = src[i];
	}
}
void fill(char str[], int size)
{
	for(int i = 0; i < size; i++)
		str[i] = '\0';
}
int utf8charsize(char frst)
{
	if(frst == '\0')
		return 0;
	if(((frst + 256) % 256) < 192)
		return 1;
	if(((frst + 256) % 256) < 224)
		return 2;
	if(((frst + 256) % 256) < 240)
		return 3;
	return 4;
}
int charindex(char str[], char regx, int ind)
{
	if(ind < 0)
		return -100;
	for(int i = ind; str[i]; i++)
	{
		if(str[i] == regx)
			return i;
	}
	return -100;
}
int strindex(char str[], char regx[], int ind)
{
	for(int i = charindex(str, regx[0], ind);str[i];i = charindex(str, regx[0], i + 1))
	{
		if(i < 0)
		{
			return -100;
		}
		for(int j = 0; regx[j] != '\0' && regx[j] == str[i + j]; j++)
		{
			if(str[i + j] == '\0')
			{
				return -100;
			}
			if(regx[j + 1] == '\0')
			{
				return i;
			}
		}
	}
	return -100;
}
int length(char string[])
{
	int i;
	for(i = 0; string[i] != '\0'; i++){}
	return i;
}
int equ(char str[], char cmpr[])
{
	for(int i = 0; str[i]; i++)
	{
		if(str[i] != cmpr[i])
			return 0;
	}
	return 1;
}
int equal(char cmprd[], char cmpr[], int size)
{
	for(int i = 0; i < size; i++)
	{
		if(cmprd[i] != cmpr[i])
		{
			return 0;
		}
	}
	return 1;
}
int power(int x, int y)
{
	int j=1;
	for(int i=0;i < y ;i++)
		j = j * x;
	return j;
}
int hexchar2int(char hex)
{
	if(hex == '0')
	return 0;
	if(hex == '1')
	return 1;
	if(hex == '2')
	return 2;
	if(hex == '3')
	return 3;
	if(hex == '4')
	return 4;
	if(hex == '5')
	return 5;
	if(hex == '6')
	return 6;
	if(hex == '7')
	return 7;
	if(hex == '8')
	return 8;
	if(hex == '9')
	return 9;
	if(hex == 'a' || hex == 'A')
	return 10;
	if(hex == 'b' || hex == 'B')
	return 11;
	if(hex == 'c' || hex == 'C')
	return 12;
	if(hex == 'd' || hex == 'D')
	return 13;
	if(hex == 'e' || hex == 'E')
	return 14;
	if(hex == 'f' || hex == 'F')
	return 15;
	return 16;
}
char int2hexchar(int intgr)
{
	if(intgr == 0)
	return '0';
	if(intgr == 1)
	return '1';
	if(intgr == 2)
	return '2';
	if(intgr == 3)
	return '3';
	if(intgr == 4)
	return '4';
	if(intgr == 5)
	return '5';
	if(intgr == 6)
	return '6';
	if(intgr == 7)
	return '7';
	if(intgr == 8)
	return '8';
	if(intgr == 9)
	return '9';
	if(intgr == 10)
	return 'a';
	if(intgr == 11)
	return 'b';
	if(intgr == 12)
	return 'c';
	if(intgr == 13)
	return 'd';
	if(intgr == 14)
	return 'e';
	if(intgr == 15)
	return 'f';
}
int str2int(char string[])
{
	int num=0;
	int ln=length(string);
	for(int i = ln; i > 0; i--)
	{
		if(string[ln - i] != '-')
			num += power(10, i - 1) * hexchar2int(string[ln - i]);
	}
	if(string[0] == '-')
		return -num;
	else
		return num;
}
void hex2str(char hex[], char str[])
{
	int i;
	for(i = 0; hex[i * 2] != '\0'; i++)
	{
		str[i] = hexchar2int(hex[i * 2]) * 16 + hexchar2int(hex[i * 2 + 1]);
	}
	str[i] = '\0';
}
void str2hex(char str[], char hex[])
{
	int i;
	for(i = 0; str[i] != '\0'; i++)
	{
		hex[i * 2] = int2hexchar(str[i] / 16);
		hex[i * 2] = int2hexchar(str[i] % 16);
	}
	hex[i * 2] = '\0';
}
void int2str(int intgr, char str[])
{
	int num, s = 0;
	if(intgr < 0)
	{
		num = -intgr;
		str[0] = '-';
		s = 1;
	}
	else
		num = intgr;
	int pow;
	for(pow = 0; num > power(10, pow) - 1; pow++){}
	for(int i = 1;i < pow + 1; i++)
	{
		str[i + s - 1] = int2hexchar(num / power(10, pow - i) - ((num / power(10, pow + 1 - i)) * 10));
		str[i + s] = '\0';
	}
}
void cat(char src[], char str[])
{
	int l=length(src);
	int i;
	for(i=0; str[i] != '\0'; i++)
	{
		src[l + i] = str[i];
	}
	src[l + i] = '\0';
}
int cut(char src[], char str[], int start, int fin)
{
	if(start == fin)
	{
		str[0] = '\0';
		return 0;
	}
	int i, j = 0;
	int beg;
	if(start < 0)
		beg = 0;
	else
		beg = start;
	if(fin < 0)
	{
		for(i = beg; src[j] != '\0'; i++)
		{
			str[j] = src[i];
			str[j + 1] = '\0';
			j++;
		}
		return 0;
	}
	for(i = beg; i < fin; i++)
	{
		str[j] = src[i];
		str[j + 1] = '\0';
		j++;
	}
	return 0;
}
void replace(char src[], char rplcd[], char rplcmnt[], char dst[])
{
	char tmp[100000];
	dst[0] = '\0';
	int i = 0;
	int j = strindex(src, rplcd, 0);
	int l = length(rplcd);
	while(i > -1)
	{
		cut(src, tmp, i, j);
		cat(dst, tmp);
		if(j > -1)
		{
			i = j + l;
			j = strindex(src, rplcd, j + l);
			cat(dst, rplcmnt);
		}
		else
			i = -1;
	}
}
void getchari(char str[], int index, char ret[])
{
	int i, j = 0, s;
	for(i = 0; j < index; i += s)
	{
		s = utf8charsize(str[i]);
		j++;
	}
	cut(str, ret, i, i + utf8charsize(str[i]));
}
void rmrep(char src[], char dst[])
{
	char newchar[5];
	char oldchar[5];
	newchar[0] = '\0';
	oldchar[0] = '\0';
	dst[0] = '\0';
	getchari(src, 0, newchar);
	for(int i = 1; newchar[0]; i++)
	{
		if(equ(newchar, oldchar))
		{
			getchari(src, i, newchar);
		}
		else
		{
			cat(dst, newchar);
			oldchar[0] = '\0';
			cat(oldchar, newchar);
			getchari(src, i, newchar);
		}
	}
}
//needed by get_sys_var.
void putivar(char dst[], char src[])
{
	int i,j;
	for(i = 0; src[i] != '='; i++){}
	i++;
	for(j = 0;src[j + i] != '\0'; j++)
	{
		dst[j] = src[i + j];
	}
	dst[j] = '\0';
}
//used inside main(argn, args[]) like: get_env_var(args, "HOME", argn, storing_string);
int get_env_var(char* list[], char var[], int num, char ret[])
{
	for(int i = num + 1; list[i]; i++)
	{
		int crct = 1;
		for(int j = 0; var[j] != '\0'; j++)
		{
			if(var[j] != list[i][j] || (var[j + 1] == '\0' && list[i][j + 1] != '='))
			{
				crct = 0;
				break;
			}
		}
		if(crct)
		{
			putivar(ret, list[i]);
			return 0;
		}
	}
	return 1;
}
//jmp is the chars/strings that are neglected. and it's seperated by ';'
//rplc is the strings that are considered the same. like '' and ". or 0 and O, l and I ... etc
//for the last example we use rplc[] = "\"=\'\';o=O=0;I=l";
//words are the filtred words seperated by ';'
void replaceAll(char src[], char dst[], char rplc[], char med[])
{
	char mainch[100];
	char replacement[100];
	int start, end = charindex(rplc, '=', 0);
	cut(rplc, mainch, 0, end);
	med[0] = '\0';
	cat(med, src);
	while(end > -1)
	{
		start = end + 1;
		end = charindex(rplc, '=', start);
		cut(rplc, replacement, start, end);
		replace(med, replacement, mainch, dst);
		med[0] = '\0';
		cat(med, dst);
	}
}
int checkwords(char str[], char words[], char jmp[], char rplc[])
{
	char txt[100000];
	char tmp[100000];
	char temp[400000];
	char replaced[4000];
	char replacement[4000];
	char rwords[400000];
	txt[0] = ' ';
	int i, j = 1;
	//filtring the string
	for(i = 0; 1; i++)
	{
		if(str[i] != ';' && str[i] != '=')
		{
			if(str[i] == '\n')
				txt[j] = ' ';
			else
				txt[j] = str[i];
			j++;
		}
		if(str[i] == '\0')
		{
			txt[j - 1] = ' ';
			txt[j] = '\0';
			break;
		}
	}
	//filtring the string from the neglected chars/strings
	int strt = 0, end = charindex(jmp, ';', strt);
	cut(jmp, replaced, strt, end);
	replace(txt, replaced, "", tmp);
	txt[0] = '\0';
	cat(txt, tmp);
	while(end > -1)
	{
		strt = end + 1;
		end = charindex(jmp, ';', strt);
		cut(jmp, replaced, strt, end);
		replace(txt, replaced, "", tmp);
		txt[0] = '\0';
		cat(txt, tmp);
	}
	//turning the filtred words to basic form
	end = -1;
	rwords[0] = '\0';
	cat(rwords, words);
	char tmpwords[100000];
	while(end > -2)
	{
		strt = end + 1;
		end = charindex(rplc, ';', strt);
		cut(rplc, temp, strt, end);
		replaceAll(rwords, tmpwords, temp, tmp);//replaceAll(src, dst, rplc,med)
		rwords[0] = '\0';
		cat(rwords, tmpwords);
	}
	//turning the text to the basic form
	end = -1;
	while(end > -2)
	{
		strt = end + 1;
		end = charindex(rplc, ';', strt);
		cut(rplc, temp, strt, end);
		replaceAll(txt, tmpwords, temp, tmp);//replaceAll(src, dst, rplc,med)
		txt[0] = '\0';
		cat(txt, tmpwords);
	}
	//checking the words
	rmrep(txt, tmp);
	txt[0] = '\0';
	cat(txt, tmp);
	end = -1;
	while(end > -2)
	{
		strt = end + 1;
		end = charindex(rwords, ';', strt);
		cut(rwords, temp, strt, end);
		if(strindex(txt, temp, 0) > -1)
			return 1;
	}
	return 0;
}

