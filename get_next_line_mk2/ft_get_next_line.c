

//静的バッファ
char *make_buffer()
{
	char *buffer=calloc(BUFFER_SIZE+1,sizeof(char));
	return buffer;
}
//データの読み取り
void read_sentence(int fd,char *buffer)
{
	read(fd,buffer,BUFFER_SIZE);
}


//改行位置の探索
int new_line_finder(char *str)
{
	int i;
	i=0;
	while(*str)
	{
		if(*str=='\n')
			return i ;
		str++;
		i++;
	}
	return 0;
}

char *ft_get_next_line(int fd)
{
	static char *buffer;
	char *tmp;
	ssize_t read_size;
	char *newline_position;
	
	if(!buffer)
	{
		buffer=make_buffer();
		if(!buffer)
			return NULL;
	}
	
	while(1)
	{
		newline_position=strchr(buffer,'\n');
		if(newline_position)
			break;
		
		temp=make_buffer();
		read_size=read_from_file(fd,temp);
		if(read_size<=0)
		{
			free(temp);
			if(read_size<0||buffer[0]=='\0')
			{
				free(buffer);
				return NULL;
			}
			return buffer; //終端　残ったbufferを返す
		}
		buffer=strjoin(buffer,temp);
		free(temp);
	}
	*newline_position='\0';
	temp=strdup(newline_position+1);
	char *line=strdup(buffer);
	free(buffer);
	buffer=temp;

	return line;
	
}
