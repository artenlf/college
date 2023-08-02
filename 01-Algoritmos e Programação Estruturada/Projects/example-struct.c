#include <stdio.h>

#define CLIENT_NAME_LENGTH 100

struct client
{
  char name[CLIENT_NAME_LENGTH];
  int age;
};

struct movie
{
  int age_rate;
  int is_available;
};

int main()
{
  struct client cli;
  struct movie mov;

  printf("\n Type the name of the client: ");

  fflush(stdin);
  fgets(cli.name, CLIENT_NAME_LENGTH, stdin);

  printf("\n Type the age of the client: ");
  scanf("%d", &cli.age);

  printf("\n Type the age rate of the movie: ");
  scanf("%d", &mov.age_rate);

  printf("\n Is the movie available? Type 1 for Yes, 0 for No.");
  scanf("%d", &mov.is_available);

  printf("\n Client: %s", cli.name);
  printf("\n Age: %d anos", cli.age);

  printf("\n Available: %d", mov.is_available);
  printf("\n Rated: %d anos", mov.age_rate);

  if ((mov.is_available) && (cli.age >= mov.age_rate))
  {
    printf("\n Client can borrow the movie");
  }
  else if (cli.age < mov.age_rate)
  {
    int how_long_to_borrow = (cli.age < mov.age_rate) * (mov.age_rate - cli.age);
    printf("\n Client is too young to borrow the movie. Movie can be borrowed in %d years.", how_long_to_borrow);
  }
  else
  {
    printf("\n Movie is unavailable to borrow at this time.");
  }
  return 0;
}