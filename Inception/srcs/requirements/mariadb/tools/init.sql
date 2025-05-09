CREATE DATABASE IF NOT EXISTS wordpress;
CREATE USER 'wp_user'@'%' IDENTIFIED BY 'secure_user_password';
GRANT ALL PRIVILEGES ON wordpress.* TO 'wp_user'@'%';
FLUSH PRIVILEGES;
