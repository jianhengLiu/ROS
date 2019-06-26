# ROS

```c
 ssh eaibot@192.168.31.200 //远程登录导航模块
```

## 1.运行程序前更新环境变量

```c
source ~/XXX_ws/devel/setup.bash
```

## 2.单独编译某一个ROS包

该法可避免每次添加新包都需全部重新编译浪费时间

```c
catkin_make [package]
```

## 3.安装工作空间中src下的package依赖项

```c
rosdep install [package]
```

## 4.source的文件

/home中ctrl+h显示隐藏文件

打开.bashrc