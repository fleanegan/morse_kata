#include "morse.h"

int is_valid_time_unit(char *in, int time_unit)
{
	char current_char;
	int i;

	while(*in)
	{
		i = 0;
		current_char = *in;
		while (*in == current_char)
		{
			in++;
			i++;
		}
		if (i % time_unit)
			return 0;
	}
	return 1;
}

char	*translate(char *trimmed_in, int time_unit)
{
	char 	*result;
	int i;
	char current_char;

	result = calloc(sizeof(char), strlen(trimmed_in));
	char *sav = result;
	while(*trimmed_in)
	{
		i = 0;
		current_char = *trimmed_in;
		while (*trimmed_in == current_char)
		{
			trimmed_in += time_unit;
			i++;
		}
		if (i == 1)
		{
			if (current_char == '1')
				*result++ = '.';
			else
				*result++ = '\t';
		}
		else if (i == 3)
			*result++ = '-';
	}
	return (sav);
}

char *decodebits(char *in)
{
	char	*result;
	int		time_unit;
	char 	*trimmed_in;

	trimmed_in = strchr(in, '1');
	if (! trimmed_in)
		return (strdup(""));
	trimmed_in = strdup(trimmed_in);
	*(strrchr(trimmed_in, '1') + 1) = 0;
	time_unit =  MIN(min_consecutive_char(trimmed_in, '1'), min_consecutive_char(trimmed_in,'0'));
	if (!is_valid_time_unit(trimmed_in, time_unit))
		return (NULL);
	return (translate(trimmed_in, time_unit));
}

int min_consecutive_char(char *in, int char_to_find)
{
	int i;
	int min = INT_MAX;

	while(*in)
	{
		i = 0;
		while (*in == char_to_find)
		{
			in++;
			i++;
		}
		if (i < min && i)
			min = i;
		while (*in && *in != char_to_find)
			in++;
	}
	return min;
}