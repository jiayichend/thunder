# 应用场景
异步响应式服务器

#  引擎使用说明 #
在文件thunder引擎说明.pptx中
#  引擎使用说明 #
目录结构说明：

**引擎核心thunder**

cmd 系统指令

codec 系统指令

labor 工作者与管理者

protocol 服务器内部与客户端通用协议

session 会话对象

step 异步访问对象

storage 存储接口对象

**第三方库**

3party

**自定义库**

llib

# 服务配置说明 #
{

    "node_type":"节点类型：HELLO，CENTER等，由业务层定义",
    "node_type":"HELLO",
    "access_host":"对系统外提供服务绑定的IP（Client to Server），若不提供对外服务，则无需配置",
    "access_host":"192.168.18.81",
    "access_port":"对系统外提供服务监听的端口",
    "access_port":9988,
    "access_codec":"接入端编解码器，目前支持  私有协议 CODEC_PRIVATE(4),http协议 CODEC_HTTP(3),CODEC_PROTOBUF(2) CODEC_PROTOBUF(2) websocket Json（与客户端通信协议） CODEC_WEBSOCKET_EX_JS,websocket Protobuf（与客户端通信协议） CODEC_WEBSOCKET_EX_PB",
    "access_codec":4,
    "gateway":"113.102.157.188",
    "gateway_port":"9988,
    "inner_host":"系统内各Server之间通信绑定的IP（Server to Server）",
    "inner_host":"192.168.18.81",
    "inner_port":"系统内各Server之间通信监听的端口",
    "inner_port":9987,
    "center":"控制中心Server",
    "center":[
        {"host":"192.168.1.11","port":"9987"},
        {"host":"192.168.1.12","port":"9987"}],
    "server_name":"异步事件驱动Server",
    "server_name":"AsyncServer",
    "process_num":"进程数量",
    "process_num":10,
    "worker_capacity":"子进程最大工作负荷",
    "worker_capacity":1000000,
    "config_path":"配置文件路径（相对路径）",
    "config_path":"conf/",
    "log_path":"日志文件路径（相对路径）",
    "log_path":"log/",
    "max_log_file_num":"最大日志文件数量，用于日志文件滚动",
    "max_log_file_num":5,
    "max_log_file_size":"单个日志文件大小限制",
    "max_log_file_size":20480000,
    "permission":"限制。addr_permit为连接限制，限制每个IP在统计时间内连接次数；uin_permit为消息数量限制，限制每个用户在单位统计时间内发送消息数量。",
    "permission":{
        "addr_permit":{"stat_interval":60.0, "permit_num":10},
        "uin_permit":{"stat_interval":60.0, "permit_num":60}
    },
    "io_timeout":"网络IO（连接）超时设置（单位：秒）小数点后面至少保留一位",
    "io_timeout":300.0,
    "step_timeout":"步骤超时设置（单位：秒）小数点后面至少保留一位",
    "step_timeout":1.5,
    "log_levels":{"FATAL":50000, "ERROR":40000, "WARN":30000, "INFO":20000, "DEBUG":10000, "TRACE":0},
    "log_level":10000,
    "refresh_interval":"刷新Server配置，检查、加载插件动态库时间周期（周期时间长短视服务器忙闲而定）",
    "refresh_interval":60,
    "so":[
        {"cmd":10001, "so_path":"plugins/Cmd1.so", "entrance_symbol":"create", "load":false, "version":1},
        {"cmd":10002, "so_path":"plugins/Cmd2.so", "entrance_symbol":"create", "load":false, "version":1}
    ],
    "module":[
        {"url_path":"util/module1", "so_path":"plugins/module1.so", "entrance_symbol":"create", "load":false, "version":1},
        {"url_path":"util/module2", "so_path":"plugins/module2.so", "entrance_symbol":"create", "load":false, "version":1}
    ],
    "custom":"自定义配置，用于通过框架层带给业务",
    "custom":{}

}


# 空载压测 #
压测工具siege
测试为单个物理机6核cpu，16G内存，200.0 GB机械硬盘，1000Mb网卡和路由。压测客户端、计算集群、存储集群在一个物理机。
单进程23255.81qps网络收发（http Web服务器）返回默认响应  300连接 分别300消息 单进程23255.81qps

# 路由 #
支持中心路由，中心节点支持热切换

# rpc #
支持状态机、协程、远程过程调用（使用匿名函数）
