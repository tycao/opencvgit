UBuntu16.10下安装ftp服务
------------------------
### 首先更新软件源，保证源是最新的，这样有利于保证在线通过apt-get install命令安装ftp。
	sudo apt-get update
### 安装vsftp : 使用sudo apt-get install vsftp命令安装vsftp，安装软件需要root权限，我们使用sudo来暂时获取。
	sudo apt-get install vsftpd
### 安装好ftp后默认是会自动创建ftp用户的，然后我们设置ftp用户的密码，输入 sudo passwd ftp，然后输入密码，再确认密码。
	sudo passwd ftp
### 创建ftp用户的家目录，使用sudo mkdir /home/ftp命令
	sudo mkdir /home/ftp
### 设置ftp家目录的权限，我这里为方便直接使用 sudo chmod 777 /home/ftp 命令将权限设置为777，当然你可以根据自己需求进行设置。
	sudo chmod 777 /home/ftp
### 对/etc/vsftpd.conf配置文件进行一定的修改。使用 sudo vi /etc/vsftpd.conf打开配置文件，如果你喜欢vim编辑器也可以使用它打开。
	sudo vi /etc/vsftpd.conf
* 打开/etc/vsftpd.conf配置文件后，对配置文件的内容进行一系列必要的修改：
	* 将配置文件中”anonymous_enable=YES “改为 “anonymous_enable=NO”（是否允许匿名ftp，若不允许选NO）
	* 取消如下配置前的注释符号：
		* local_enable=YES（是否允许本地用户登录）
		* write_enable=YES（是否允许本地用户写的权限）
		* chroot_local_user=YES（是否将所有用户限制在主目录）
		* chroot_list_enable=YES（是否启动限制用户的名单）
		* chroot_list_file=/etc/vsftpd.chroot_list（可在文件中设置多个账号）
![ftp_02](https://github.com/tycao/opencvgit/blob/master/FTP/src/ftp_02.png "ftp_02")
![ftp_01](https://github.com/tycao/opencvgit/blob/master/FTP/src/ftp_01.png "ftp_01")
### 然后创建上述chroot_list_file文件的路径 ： /etc/vsftpd.chroot_list
	touch /etc/vsftpd.chroot_list
	sudo chmod 777 /etc/vsftpd.chroot_list
然后在/etc/vsftpd.chroot_list文件里，添加ftp用户：ftp
![ftp_03](https://github.com/tycao/opencvgit/blob/master/FTP/src/ftp_03.png "ftp_03")

### 测试ftp，复制一些文件到/home/ftp目录下
* 方法一：在浏览器中输入ftp://localhost，网页登录。
![ftp_05](https://github.com/tycao/opencvgit/blob/master/FTP/src/ftp_05.png "ftp_05")
![ftp_06](https://github.com/tycao/opencvgit/blob/master/FTP/src/ftp_06.png "ftp_06")
* 方法二：在终端中输入ftp localhost，然后输入用户名与密码实现登录。
![ftp_04](https://github.com/tycao/opencvgit/blob/master/FTP/src/ftp_04.png "ftp_04")

### 如果登录ftp总是出现密码错误，可以将/etc/vsftpd.conf配置文件的pam_service_name=vsftpd改为pam_service_name=ftp，即可解决。
![ftp_07](https://github.com/tycao/opencvgit/blob/master/FTP/src/ftp_07.png "ftp_07")
### 链接
[具体可以参考百度经验，还是蛮有用的](https://jingyan.baidu.com/article/7908e85c988b23af481ad2ae.html)



	
	
	
ubuntu下安装vftp 安装vsftpd后，登录ftp服务器时，会提示错误： 530 Login incorrect
==================================================
* 更换国内源；

* 刷新源：sudo apt-get update

* sudo apt-get install vsftpd

* 新建"/home/uftp"目录作为用户主目录打开"终端窗口"，输入"sudo mkdir /home/uftp"-->回车-->输入"sudo ls /home"-->回车-->有一个uftp目录，目录新建成功。

* 新建用户uftp并设置密码打开"终端窗口"，输入"sudo useradd -d /home/uftp -s /bin/bash uftp"-->回车-->用户新建成功-->输入"sudo passwd uftp"设置uftp用户的密码-->回车-->输入两次密码-->回车-->密码设置成功。

* 使用gedit修改配置文件/etc/vsftpd.conf打开"终端窗口"，输入"sudo gedit /etc/vsftpd.conf"-->回车-->打开了vsftpd.conf文件，向文件中添加:
	* userlist_deny=NO 
	* userlist_enable=YES 
	* userlist_file=/etc/allowed_users
	* seccomp_sandbox=NO -->使文件中的"local_enable=YES"-->保存。
![ftp_08](https://github.com/tycao/opencvgit/blob/master/FTP/src/ftp_08.png "ftp_08")
!["ftp_02"](https://github.com/tycao/opencvgit/blob/master/FTP/src/ftp_02.png "ftp_02")
### 然后在上述 userlist_file=/etc/allowed_users 下创建 /etc/allowed_users
	touch /etc/allowed_users
	sudo chmod 777 /etc/allowed_users
	在/etc/allowed_users里添加ftp用户：ftp

![ftp_09](https://github.com/tycao/opencvgit/blob/master/FTP/src/ftp_09.png "ftp_09")

* 使用gedit查看/etc/ftpusers文件中的内容打开"终端窗口"，输入"sudo gedit /etc/ftpusers"-->回车-->打开这个文件后，看一看有没有uftp这个用户名，如果没有，就直接退出。如果有就删除uftp,
因为这个文件中记录的是不能访问FTP服务器的用户清单。（去掉root）


### 链接
[具体如何解决 "530 Login incorrect" 的ftp登录问题，可以参考此链接](http://www.cnblogs.com/bqx619/p/5021458.html)
