UBuntu16.10下安装ftp服务
------------------------
## 首先更新软件源，保证源是最新的，这样有利于保证在线通过apt-get install命令安装ftp。
	sudo apt-get update
## 安装vsftp : 使用sudo apt-get install vsftp命令安装vsftp，安装软件需要root权限，我们使用sudo来暂时获取。
	sudo apt-get install vsftpd
## 安装好ftp后默认是会自动创建ftp用户的，然后我们设置ftp用户的密码，输入 sudo passwd ftp，然后输入密码，再确认密码。
	sudo passwd ftp
## 创建ftp用户的家目录，使用sudo mkdir /home/ftp命令
	sudo mkdir /home/ftp
## 设置ftp家目录的权限，我这里为方便直接使用 sudo chmod 777 /home/ftp 命令将权限设置为777，当然你可以根据自己需求进行设置。
	sudo chmod 777 /home/ftp
## 对/etc/vsftpd.conf配置文件进行一定的修改。使用 sudo vi /etc/vsftpd.conf打开配置文件，如果你喜欢vim编辑器也可以使用它打开。
	sudo vi /etc/vsftpd.conf
* 打开/etc/vsftpd.conf配置文件后，对配置文件的内容进行一系列必要的修改
** 将配置文件中”anonymous_enable=YES “改为 “anonymous_enable=NO”（是否允许匿名ftp，若不允许选NO）
** 取消如下配置前的注释符号：
	local_enable=YES（是否允许本地用户登录）
	write_enable=YES（是否允许本地用户写的权限）
	chroot_local_user=YES（是否将所有用户限制在主目录）
	chroot_list_enable=YES（是否启动限制用户的名单）
	chroot_list_file=/etc/vsftpd.chroot_list（可在文件中设置多个账号）
![](ftp_02)
![](ftp_01)
## 然后创建上述chroot_list_file文件的路径 ： /etc/vsftpd.chroot_list
	touch /etc/vsftpd.chroot_list
	sudo chmod 777 /etc/vsftpd.chroot_list
然后在/etc/vsftpd.chroot_list文件里，添加ftp用户：ftp

	
	
	
或者用如下的方法修改/etc/vsftpd.conf配置文件的内容：
==================================================
