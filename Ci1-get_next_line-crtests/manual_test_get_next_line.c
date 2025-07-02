/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manual_test_get_next_line.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 10:32:25 by reciak            #+#    #+#             */
/*   Updated: 2025/07/02 18:10:06 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file manual_test_get_next_line.c
 * @brief This tests were started by just copying over tests from my first try
 *        of the Common Core.
 */

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "get_next_line.h"

void openall(int *fd)
{
    char *filename01 = "test01.txt";
	char *filename02 = "test02.txt";
	char *filename03 = "test03_tiny_segfault_hunting.txt";
	char *filename04 = "test04_emptyfile.txt";
	char *filename05 = "test01.txt";
	char *filename06 = "test05_I_do_not_exist_at_all.txt";

	printf("\n*************************************************************\n");
    printf("open returned filedescr:|%d|", fd[1] = open(filename01, O_RDONLY));
		printf(" for file %s\n", filename01);
	printf("open returned filedescr:|%d|", fd[2] = open(filename02, O_RDONLY));
		printf(" for file %s\n", filename02);
	printf("open returned filedescr:|%d|", fd[3] = open(filename03, O_RDONLY));
		printf(" for file %s\n", filename03);
	printf("open returned filedescr:|%d|", fd[4] = open(filename04, O_RDONLY));
		printf(" for file %s\n", filename04);
	printf("open returned filedescr:|%d|", fd[5] = open(filename05, O_RDONLY));
		printf(" for file %s\n", filename05);
	printf("open returned filedescr:|%d|", fd[6] = open(filename06, O_RDONLY));
		printf(" for file %s\n", filename06);
	// The above file does not exist -> check behaviour in that case as well
}

void closeall(int *fd)
{
	close(fd[1]);
	close(fd[2]);
	close(fd[3]);
	close(fd[4]);
	close(fd[5]);
	close(fd[6]);
}

int	single_test_gnl(int *fd, int filenumber)
{
	static int	counts_vists = 0;
	char		*str;

	if (fd[filenumber] == -1) 
	{
        printf("File not found or can't be opened.");
		printf("(filenumber: %d, fd[%d]: %d)", 
			filenumber, filenumber, fd[filenumber]);
		printf("For testing reasons I will pass the filedesciptor ");
		printf("non the less to get_next_line\n");
//        return (false); // For testing reasons: Commented out so that the
//                        // invalid filedescriptor is passed to get_next_line
    }
	counts_vists += 1;
	printf("┌\n|Call %d:\n└", counts_vists);
	
	str = get_next_line(fd[filenumber]);
	for (int i = 1; i < 4*(filenumber) - 1 ; i++) 
	{
        printf("%c", '\t');
    }
	printf("\tfd: %d -->|%s|<--\n", fd[filenumber], str);
	if (str == NULL)
		return (0);
	else
	{
		free(str);
		return (1);
	}
}

void test_gnl_bonus(int *fd)
{
	printf("\n- - - - - - - - - - - - - - - This is  test_gnl_bonus");
	printf(" - - - - - - - - - - - - - - - \n");
	single_test_gnl(fd, 1);
	single_test_gnl(fd, 2);
	single_test_gnl(fd, 3);
	single_test_gnl(fd, 3);
	single_test_gnl(fd, 1);
	single_test_gnl(fd, 2);
	single_test_gnl(fd, 1);
	single_test_gnl(fd, 1);
	single_test_gnl(fd, 4);
	single_test_gnl(fd, 2);
	single_test_gnl(fd, 3);
	single_test_gnl(fd, 3);
	single_test_gnl(fd, 4);
	single_test_gnl(fd, 4);
	single_test_gnl(fd, 5);
	single_test_gnl(fd, 1);
	single_test_gnl(fd, 2);
	single_test_gnl(fd, 5);
	single_test_gnl(fd, 2);
	single_test_gnl(fd, 1);
	single_test_gnl(fd, 4);
	single_test_gnl(fd, 4);
	single_test_gnl(fd, 6);
	single_test_gnl(fd, 1);
	single_test_gnl(fd, 2);
	single_test_gnl(fd, 6);
	single_test_gnl(fd, 2);
	single_test_gnl(fd, 5);
	single_test_gnl(fd, 2);
}	

void test_gnl_read_whole_files(int *fd)
{
	printf("\n- - - - - - - - - - - - - - - - - ");
	printf("This is  test_gnl_read_whole_file");
	printf(" - - - - - - - - - - - - - - - - -\n");
	for (int i = 1; i <= 6; ++i)
	{
		while (single_test_gnl(fd, i));
		printf ("--------\n");
		printf ("-------> File (fd:%d) should now be fully read;\n", fd[i]);
		printf ("--------\n");
	}
}

void test_gnl_read_whole_files_and_extra_times_after(int *fd)
{
	printf("\n- - - - - - - - - - - - - - - - - ");
	printf("This is test_gnl_read_whole_files_and_extra_times_after - -\n");
	for (int i = 1; i <= 6; ++i)
	{
		while (single_test_gnl(fd, i));
		printf ("--------\n");
		printf ("-------> File (fd:%d) should now be fully read;" , fd[i]);
		printf ("\n-------- Trying now what happens if gnl is called ");
		printf ("%d more times:\n", i);
		printf ("--------\n");
		for (int j = 1; j <= i; ++j)
		{
			single_test_gnl(fd, i);
		}
	}
}

void tests_gnl(void) 
{
	int fd[7];

	openall(fd);
		test_gnl_bonus(fd);
	closeall(fd);

	openall(fd);
		test_gnl_read_whole_files(fd);
	closeall(fd);

	openall(fd);
		test_gnl_read_whole_files_and_extra_times_after(fd);
	closeall(fd);

	printf("\nENDED: tests_gnl\n");
}

int main (void)
{
	tests_gnl();
}
