


char *get_next_line(int fd)
{
	static char *buffer;
	ssize_t read_size;
	int newline_position;
	char *tmp;
	char *line;
	int flag;

	flag=0;


	if(!buffer)
	{
		buffer=make_buffer();
		if(!buffer)
			return NULL;
		flag=1;
	}

	while(1)
	{
		newline_position=find_new_line(buffer);
		if(newline_position!=-1)
			break;

		tmp=make_buffer(); //tmp error buffer　leak
		if(!tmp)return NULL;

		read_size=read_from_file(fd,tmp);
		if(read_size<=0)
		{
			free(tmp);
			if(read_size<0)
			{
				free(buffer);
				buffer=NULL;
			}
			if(*buffer==0)
				return NULL;  //	問題はbufferに何か文字が保管されているかどうかだ。読み込むものがないかつ、バッファーにも文字がないのなら、そもそも読み込むものは最初からない。
			return buffer;        //        仮に、前回の処理によってバッファーにあるものが全て読み込まれても、必ず\nは残るようになっているはず。

		}

		char *old_buffer=buffer;
		buffer=str_join(buffer,tmp);
		free(old_buffer);
		free(tmp);
		if(!buffer)
			return NULL;
	}

	buffer[newline_position]='\0';
	line=strdup(buffer);
	tmp=strdup(buffer+newline_position+1);
	free(buffer);
	buffer=tmp;
	retrun line;
}

