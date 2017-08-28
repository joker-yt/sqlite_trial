#include <stdio.h>
#include <sqlite3.h>


static int callback(void* NotUsed, int argc, char** argv, char **azColName)
{
	for (int i = 0; i < argc; ++i)
	{
		printf ("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
	}
	printf("\n");

	return 0;
}


int main(int argc, char *argv[])
{
	printf("%s: Enter\n", __func__);

	sqlite3 *db;

	char *zErrMsg = 0;
	int rc;

	rc = sqlite3_open(argv[1], &db);
	if (rc)
	{
		printf("%s msg\n", __func__);
		sqlite3_close(db);
		return -1;
	}

	rc = sqlite3_exec(db, argv[2], callback, 0, &zErrMsg);

	rc = sqlite3_close(db);

    printf("%s: Done\n", __func__);	

    return 0;
}

