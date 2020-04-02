#include <cqcppsdk/cqcppsdk.hpp>
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;
using cq::utils::s2ws;
using cq::utils::ws2s;
using cq::can_send_image;
using cq::can_send_record;
using cq::send_group_message;
using cq::send_message;
using namespace cq;
bool enabled=true;
bool sfd=false;
CQ_INIT{
    on_group_message([](const auto &event)
    {
        try {
            int random;
            if(event.message=="pls fd off")
            {
                if(enabled==false)
                {
                    send_message(event.target,"复读机已经是禁用状态了。");
                }
                else
                {
                    enabled=false;
                    send_message(event.target,"复读机已禁用。");
                }
            }
            else if(event.message=="pls fd on")
            {
                if(enabled==true)
                {
                    send_message(event.target,"复读机已经是启用状态了。");
                }
                else
                {
                    enabled=true;
                    send_message(event.target,"复读机已启用。");
                }
            }
            if(event.message=="pls superfd on" && event.user_id==1604180254)
            {
                if(sfd==true)
                {
                    send_message(event.target,"超级复读机已经是启用状态了。");
                }
                else
                {
                    sfd=true;
                    send_message(event.target,"超级复读机已启用。");
                }
            }
            else if(event.user_id!=1604180254 && event.message=="pls superfd on")
            {
                send_message(event.target,"你没有权限。");
            }
            if(event.message=="pls superfd off" && event.user_id==1604180254)
            {
                if(sfd==false)
                {
                    send_message(event.target,"超级复读机已经是关闭状态了。");
                }
                else
                {
                    sfd=false;
                    send_message(event.target,"超级复读机已关闭。");
                }
            }
            else if(event.user_id!=1604180254 && event.message=="pls superfd on")
            {
                send_message(event.target,"你没有权限。");
            }
            random=rand();
            if(random%9==0 && enabled==true)
            {
                    send_message(event.target,event.message);
            }
            else if(sfd==true)
            {
                send_message(event.target,event.message);
            }
        } catch (ApiError &err)
        {
            logging::warning("PM","Error");
        }
    });
}