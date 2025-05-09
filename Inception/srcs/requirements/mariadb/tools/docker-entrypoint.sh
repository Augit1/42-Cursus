#!/bin/sh

set -e

if [ ! -d "/var/lib/mysql/mysql" ]; then
    echo "=> Database directory is empty. Initializing..."
    mysql_install_db --user=mysql --datadir=/var/lib/mysql

    mysqld --user=mysql --datadir=/var/lib/mysql --skip-networking &
    pid="$!"

    echo "=> Waiting for MariaDB to start..."
	
	# Waiting for daemon MariaDB
	while ! mysqladmin ping --silent; do
		sleep 1
	done

	echo "=> Running init scripts in /docker-entrypoint-initdb.d..."

	if [ -f "/docker-entrypoint-initdb.d/init.sql" ]; then
		envsubst < /docker-entrypoint-initdb.d/init.sql > /tmp/init.sql
		mv /tmp/init.sql /docker-entrypoint-initdb.d/init.sql
	fi

	for f in /docker-entrypoint-initdb.d/*.sql; do
		[ -f "$f" ] && mysql < "$f"
	done


	echo "=> Stopping background MariaDB..."
	# Stop the server background
	mysqladmin shutdown
	wait "$pid"
fi

echo "=> Starting MariaDB in foreground..."

# Launch MariaDB upfront (PID 1)
exec mysqld --user=mysql --datadir=/var/lib/mysql
