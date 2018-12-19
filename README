# 接口描述

## 启动解码引擎

```c
bool im_open_decoder(const char *fn_sys_dict, const char *fn_usr_dict);
```

* fn_sys_dict: 系统字典，可以直接使用谷歌自带的字典`dict_pinyin.dat`
* fn_usr_dict: 用户字典，用户自己定义的字典
成功启动引擎时接口返回true。


```c
bool im_open_decoder_fd(int sys_fd, long start_offset, long length,
                          const char *fn_usr_dict);
```

上一个函数的变形。
* sys_fd: 系统字典的文件描述符
* start_offset: 系统字典文件描述符的偏移位置
* length: 系统字典文件读取的长度
* fn_usr_dict: 用户字典

## 关闭解码引擎

```c
void im_close_decoder();
```

## 设置输入输出上限

```c
void im_set_max_lens(size_t max_sps_len, size_t max_hzs_len);
```

如果本函数未被调用，则使用默认参数。举例说明该函数的作用，对于显示屏幕大小受限制，
显示部件可以只显示确定数量的输入字母来解码， 以及确定数量的中文来显示。
如果用户添加一个新字母之母， 输入的所有字母或输出的中文数量超过了设置的上限， 则引擎会不理踩
新添加的字母。
* max_sps_len: 输入拼音字母的最大长度
* max_hzs_len: 解码中文字符的最大长度

## 清除缓冲

```c
void im_flush_cache();
```

因为引擎在运行时，为是达到最好的性能，一些数据有保存至内存中，所以有必要时需要清除掉。

## 搜索

```c
size_t im_search(const char* sps_buf, size_t sps_len);
```

本函数用于搜索匹配字母的候选中文。当要搜索的字母的前缀与先前的搜索字母一样，引擎默认会在先前的
搜索结果中进行搜索。如果用户需要开启新的搜索，可以先调用`im_reset_search()`接口。
* sps_buf: 拼音字母
* sps_len: 字母长度
* 返回候选数


## 删除

```c
size_t im_delsearch(size_t pos, bool is_pos_in_splid, bool clear_fixed_this_step);
```

对当前查找结果执行删除操作， 然后再重新查找。
* pos:  拼音字母的位置或者是搜索结果ID
* is_pos_in_splid: 申明pos参数是字母位置还是搜索结果ID
* clear_fixed_this_step:
* 返回候选数量


## 初始化查找结果

```c
void im_reset_search();
```

## 获取输入的拼音字母

```c
const char *im_get_sps_str(size_t *decoded_len);
```

* decoded_len: 保存返回拼音字母的长度arsed.
* 返回拼音字母

## 获取候选字符串

```c
char16* im_get_candidate(size_t cand_id, char16* cand_str, size_t max_len);
```
* cand_id:  获取候选字符串的ID号，从0开始，通常ID为0是匹配度最高的
* cand_str: 用于保存选择字符串的缓冲区
* max_len: 缓冲区最大长度
* 成功返回缓冲区地址cand_str，失败返回NULL.
