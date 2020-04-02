#include <iostream>
#include <set>
#include <sstream>
#include <cmath>
#include <random>
#include <time.h>
#include <stdlib.h>
#include <cstring>
#include <string>
#include <fstream>
#include <cqcppsdk/cqcppsdk.h>

using namespace cq;
using namespace std;
using Message = cq::message::Message;
using MessageSegment = cq::message::MessageSegment;
using cq::utils::s2ws;
using cq::utils::ws2s;
using cq::can_send_image;
using cq::can_send_record;
using cq::send_group_message;
using cq::send_message;
using namespace cq;
using namespace dir;

CQ_INIT {
    on_enable([] { logging::info("启用", "插件已启用"); });

    on_group_message([](const auto &event) {
        try {
            if(event.message=="pls zc")
            {
                int token;
                token=rand();
                if(token%5==0)
                {
                    send_message(event.target,MessageSegment::at(event.user_id)+"你照张自拍就是全家福。");
                }
                else if(token%7==0)
                {
                    send_message(event.target,MessageSegment::at(event.user_id)+"你出生的时候是不是被扔了三次,被接住了两次");
                }
                else if(token%11==0)
                {
                    send_message(event.target,MessageSegment::at(event.user_id)+"从小妈妈就告诉我，对人要怀有善意，后来我接触了很多人，发现了不是所有人都有妈妈。​​");
                }
                else if(token%17==0)
                {
                    send_message(event.target,MessageSegment::at(event.user_id)+"我是算命的，请问您算什么东西?");
                }
                else if(token%3==0)
                {
                    send_message(event.target,MessageSegment::at(event.user_id)+"你这种脑残程度我称之为稀有物种。");
                }
                else if(token%6==0)
                {
                    send_message(event.target,MessageSegment::at(event.user_id)+"如果思考是生存的证明，我很难判断你是不是一具尸体。");
                }
                else if(token%2==0)
                {
                    send_message(event.target,MessageSegment::at(event.user_id)+"你家住海边吗？管得这么宽。");
                }
                else
                {
                    send_message(event.target,MessageSegment::at(event.user_id)+"如果梦到你，那真是见鬼。");
                }               
            }
        } catch (ApiError &err) {
            logging::warning("Yee", "Error, 错误码: " + to_string(err.code));
        }
    });

}

CQ_MENU(menu_demo_1) {
    logging::info("菜单", "点击菜单1");
}

CQ_MENU(menu_demo_2) {
    send_private_message(10000, "测试");
}
