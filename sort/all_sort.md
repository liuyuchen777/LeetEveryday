# 排序的方法

## 冒泡排序

把剩余数组中最小的数交换到当前未排序的第一个位置

## 插入排序

将一个记录插入到已经排序好的有序表中

针对少量元素非常有效

## 选择排序

第一次从待排序的数据元素中选出最小的放到数列最起始的位置，再从剩余的未排序元素中寻找最小的元素放到已排序序列的末尾（相比于冒泡排序，交换的次数更少，比较的次数更多）

## 快速排序

分而治之的算法。每次选定一个数，小于这个数的放在这个数左边，大于这个数的放在这个数右边

交换的时候先从左到右寻找比选定数大的，然后右到左寻找比选定数小的，交换。重复知道i >= j

## 希尔排序

希尔排序是一种改进的插入排序算法，缩小增量排序

![shell](./pic/shell.png)

## 归并排序

划分为一个一个更小的数组，然后合并有序数组

## 堆排序

最大堆：最大的元素出现根节点，子节点大于或等于父节点（堆首先是一个完全二叉树，可以用数组存储）

排序时先建立堆，然后再一个一个去除根节点