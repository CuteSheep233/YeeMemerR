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

int rand_X(int x)
{
    return rand()%x;
}
CQ_INIT {
    on_group_message([](const auto &event) {
        try {
            //searchforcoins
            if(event.message=="pls game search")
            {
                int token;
                token=rand();
                if(token%5==0)
                {  
                    send_message(event.target,MessageSegment::at(event.user_id)+"搜索了更衣室,你找到了 10 枚金币。");
                    send_message(event.target,"10 枚金币已经进入你的钱包,闻起来像汗衫。");
                    send_message(event.target,MessageSegment::image("gys.png"));
                    string Path;
                    string root;
                    root=dir::app();
                    string userid;
                    userid=to_string(event.user_id);
                    Path=root+userid+"_coin.ini";
                    
                    int temp;
                    ifstream infile (s2ws(Path));
                    infile>>temp;
                    infile.close();
                    if(temp<0)
                    {
                        temp=0;
                    }
                    fstream Stream(s2ws(Path), fstream::out | ios_base::trunc);
                    Stream.close();
                    ofstream Write(s2ws(Path));
                    Write<<temp+10<<endl;
                    //Credits to Frisk in SDK Support group.
                }
                else if(token%7==0)
                {
                    send_message(event.target,MessageSegment::at(event.user_id)+"你搜索了撤硕,你找到了 14 枚金币。");
                    send_message(event.target,"24 枚金币已经进入你的钱包,闻起来...无法用言语表达。");
                    send_message(event.target,MessageSegment::image("thing.png"));
                    string Path;
                    string root;
                    root=dir::app();
                    string userid;
                    userid=to_string(event.user_id);
                    Path=root+userid+"_coin.ini";
                    ifstream infile (s2ws(Path));
                    int temp;
                    infile>>temp;
                    infile.close();
                    if(temp<0)
                    {
                        temp=0;
                    }
                    fstream Stream(s2ws(Path), fstream::out | ios_base::trunc);
                    Stream.close();
                    ofstream Write(s2ws(Path));
                    Write<<temp+14<<endl;
                    Write.close();
                }
                else if(token%3==0)
                {
                    send_message(event.target,MessageSegment::at(event.user_id)+"你搜索了医院,你找到了 18 枚金币。");
                    send_message(event.target,"18 枚金币已经进入你的钱包,闻起来像药物。");
                    string Path;
                    string root;
                    root=dir::app();
                    string userid;
                    userid=to_string(event.user_id);
                    Path=root+userid+"_coin.ini";
                    ifstream infile (s2ws(Path));
                    int temp;
                    infile>>temp;
                    infile.close();
                    if(temp<0)
                    {
                        temp=0;
                    }
                    fstream Stream(s2ws(Path), fstream::out | ios_base::trunc);
                    Stream.close();
                    ofstream Write(s2ws(Path));
                    Write<<temp+18<<endl;
                    Write.close();
                }
                else if(token%2==0)
                {
                    send_message(event.target,MessageSegment::at(event.user_id)+"你搜索了麦当劳,你找到了 10 枚金币。");
                    send_message(event.target,"10 枚金币已经进入你的钱包,闻起来像薯条。");
                    send_message(event.target,MessageSegment::image("mcdoanlds.png"));
                    string Path;
                    string root;
                    root=dir::app();
                    string userid;
                    userid=to_string(event.user_id);
                    Path=root+userid+"_coin.ini";
                    ifstream infile (s2ws(Path));
                    int temp;
                    infile>>temp;
                    infile.close();
                    if(temp<0)
                    {
                        temp=0;
                    }
                    fstream Stream(s2ws(Path), fstream::out | ios_base::trunc);
                    Stream.close();
                    ofstream Write(s2ws(Path));
                    Write<<temp+10<<endl;
                    Write.close();
                }
                else
                {
                    send_message(event.target,MessageSegment::at(event.user_id)+"非酋，你什么也没找到!");
                }
            }
            //Balance-info
            if(event.message=="pls game bal")
            {
                string Path;
                string root;
                root=dir::app();
                string userid;
                userid=to_string(event.user_id);
                Path=root+userid+"_coin.ini";
                int temp;
                string c;
                ifstream infile (s2ws(Path));  
                infile>>temp;
                infile.close();
                if(temp<0)
                {
                    temp=0;
                }
                c=to_string(temp);
                fstream Stream(s2ws(Path), fstream::out | ios_base::trunc);
                Stream.close();
                ofstream Write(s2ws(Path));
                Write<<temp<<endl;
                Write.close();
                send_message(event.target,MessageSegment::at(event.user_id)+"钱包余额:"+c+"金币");
            }
            //shop
            if(event.message=="pls game shop")
            {
                string Path;
                string root;
                root=dir::app();
                string userid;
                userid=to_string(event.user_id);
                Path=root+userid+"_coin.ini";
                int coins;
                string cs;
                ifstream infile (s2ws(Path));
                infile>>coins;
                infile.close();
                if(coins<0)
                {
                    coins=0;
                }
                cs=to_string(coins);
                send_message(event.target,MessageSegment::at(event.user_id)+"欢迎来到商店，要买点什么吗？");
                send_message(event.target,"你有"+cs+"枚金币。");
                send_message(event.target,"pls buy lt - 购买笔记本电脑(350金币)[工具,可以发送梗图赚钱]");
            }
            if(event.message=="pls buy lt")
            {
                string Path;
                string root;
                root=dir::app();
                string userid;
                userid=to_string(event.user_id);
                Path=root+userid+"_coin.ini";
                int coins;
                ifstream infile (s2ws(Path));
                infile>>coins;
                infile.close();
                if(coins<0)
                {
                    coins=0;
                }
                if(coins<350)
                {
                    int rc;
                    string rcs;
                    rc=350-coins;
                    rcs=to_string(rc);
                    send_message(event.target,"穷鬼，你的钱不够！你还需要:"+rcs+"枚金币！");
                    send_message(event.target,"错误:余额不足 错误码:667(BAL)");
                    ofstream store(s2ws(Path));
                    store<<coins<<endl;
                    store.close();
                }
                else
                {
                    string Pathi;
                    Pathi=root+userid+"_olt.ini";
                    int owned;
                    ifstream infile (s2ws(Pathi));
                    infile>>owned;
                    infile.close();
                    if(owned<0)
                    {
                        owned=0;
                    }
                    if(owned==0)
                    {
                        fstream Stream(s2ws(Pathi), fstream::out | ios_base::trunc);
                        Stream.close();
                        ofstream Write(s2ws(Path));
                        Write<<coins-350<<endl;
                        Write.close();
                        ofstream store(s2ws(Pathi));
                        store<<1<<endl;
                        store.close();
                        string rcs;
                        int cs;
                        cs=coins-350;
                        rcs=to_string(cs);
                        send_message(event.target,"你已经购买了 笔记本电脑 ,你还剩"+rcs+"枚金币。");
                    }
                    else
                    {
                        send_message(event.target,"你已经拥有这个物品了！");
                        send_message(event.target,"错误:物品已存在 错误码:778(INV)");
                    }
                }
            }
            //pm
                if(event.message=="pls game pm")
                {
                    string userid=to_string(event.user_id);
                    string root=dir::app();
                    int token;
                    token=rand();
                    string Pathi;
                    Pathi=root+userid+"_olt.ini";
                    int owned;
                    ifstream infile (s2ws(Pathi));
                    infile>>owned;
                    infile.close();
                    if(owned<0)
                    {
                        owned=0;
                        ofstream store(s2ws(Pathi));
                        store<<owned<<endl;
                        store.close();
                    }
                    if(owned==1)
                    {
                        if(token%3==0)
                        {
                            send_message(event.target,MessageSegment::at(event.user_id)+"你的梗图获得了300赞，你获得了 30 金币！");
                            string Path;
                            string root;
                            root=dir::app();
                            string userid;
                            userid=to_string(event.user_id);
                            Path=root+userid+"_coin.ini";
                            int temp;
                            ifstream infile (s2ws(Path));
                            infile>>temp;
                            infile.close();
                            if(temp<0)
                            {
                                temp=0;
                            }
                            fstream Stream(s2ws(Path), fstream::out | ios_base::trunc);
                            Stream.close();
                            ofstream Write(s2ws(Path));
                            Write<<temp+30<<endl;
                            Write.close();
                        }
                        else if(token%5==0)
                        {
                            send_message(event.target,MessageSegment::at(event.user_id)+"你的梗图火了,获得了2000赞，你获得了 100 金币！");
                            string Path;
                            string root;
                            root=dir::app();
                            string userid;
                            userid=to_string(event.user_id);
                            Path=root+userid+"_coin.ini";
                            int temp;
                            ifstream infile (s2ws(Path));
                            infile>>temp;
                            infile.close();
                            if(temp<0)
                            {
                                temp=0;
                            }
                            fstream Stream(s2ws(Path), fstream::out | ios_base::trunc);
                            Stream.close();
                            ofstream Write(s2ws(Path));
                            Write<<temp+100<<endl;
                            Write.close();
                        }
                        else if(token%7==0)
                        {
                            send_message(event.target,MessageSegment::at(event.user_id)+"你的梗图获得了100赞，你获得了 10 金币！");
                            string Path;
                            string root;
                            root=dir::app();
                            string userid;
                            userid=to_string(event.user_id);
                            Path=root+userid+"_coin.ini";
                            int temp;
                            ifstream infile (s2ws(Path));
                            infile>>temp;
                            infile.close();
                            if(temp<0)
                            {
                                temp=0;
                            }
                            fstream Stream(s2ws(Path), fstream::out | ios_base::trunc);
                            Stream.close();
                            ofstream Write(s2ws(Path));
                            Write<<temp+10<<endl;
                            Write.close();
                        }
                        else if(token%8==0)
                        {
                            send_message(event.target,MessageSegment::at(event.user_id)+"你的梗图获得了500赞，你获得了 50 金币！");
                            string Path;
                            string root;
                            root=dir::app();
                            string userid;
                            userid=to_string(event.user_id);
                            Path=root+userid+"_coin.ini";
                            int temp;
                            ifstream infile (s2ws(Path));
                            infile>>temp;
                            infile.close();
                            if(temp<0)
                            {
                                temp=0;
                            }
                            fstream Stream(s2ws(Path), fstream::out | ios_base::trunc);
                            Stream.close();
                            ofstream Write(s2ws(Path));
                            Write<<temp+100<<endl;
                            Write.close();
                        }
                        else if(token%6==0)
                        {
                            send_message(event.target,MessageSegment::at(event.user_id)+"你的梗图获得了800赞，你获得了 80 金币！");
                            string Path;
                            string root;
                            root=dir::app();
                            string userid;
                            userid=to_string(event.user_id);
                            Path=root+userid+"_coin.ini";
                            int temp;
                            ifstream infile (s2ws(Path));
                            infile>>temp;
                            infile.close();
                            if(temp<0)
                            {
                                temp=0;
                            }
                            fstream Stream(s2ws(Path), fstream::out | ios_base::trunc);
                            Stream.close();
                            ofstream Write(s2ws(Path));
                            Write<<temp+100<<endl;
                            Write.close();
                        }
                        else if(token%33==0)
                        {
                            send_message(event.target,MessageSegment::at(event.user_id)+"你的梗图火爆了，获得了5000赞，你获得了 500 金币！");
                            string Path;
                            string root;
                            root=dir::app();
                            string userid;
                            userid=to_string(event.user_id);
                            Path=root+userid+"_coin.ini";
                            int temp;
                            ifstream infile (s2ws(Path));
                            infile>>temp;
                            infile.close();
                            if(temp<0)
                            {
                                temp=0;
                            }
                            fstream Stream(s2ws(Path), fstream::out | ios_base::trunc);
                            Stream.close();
                            ofstream Write(s2ws(Path));
                            Write<<temp+100<<endl;
                            Write.close();
                        }
                        else
                        {
                            send_message(event.target,MessageSegment::at(event.user_id)+"你的梗图被冷落了，你什么也没获得。");
                        }
                    }
                    else if(owned==0)
                    {
                        send_message(event.target,MessageSegment::at(event.user_id)+"啧，你需要一个笔记本电脑才可以做这个！");
                        send_message(event.target,"错误:物品缺失 错误码:778(INV)");
                    }
                }
                //channel info
                if(event.message=="pls game cha")
                {
                    string Paths,Pathb,Pathv;
                    string root;
                    root=dir::app();
                    string userid;
                    userid=to_string(event.user_id);
                    Pathv=root+userid+"_views.ini";
                    Paths=root+userid+"_subs.ini";
                    Pathb=root+userid+"_coin.ini";
                    int sub,bal,views;
                    ifstream infile (s2ws(Paths));
                    infile>>sub;
                    infile.close();
                    ifstream loadb (s2ws(Pathb));
                    loadb>>bal;
                    loadb.close();
                    ifstream loadv (s2ws(Pathv));
                    loadv>>views;
                    loadv.close();
                    if(sub<0)
                    {
                        sub=0;
                        fstream Stream(s2ws(Paths), fstream::out | ios_base::trunc);
                        Stream.close();
                        ofstream fixs(s2ws(Paths));
                        fixs<<sub<<endl;
                        fixs.close();
                    }
                    if(bal<0)
                    {
                        bal=0;
                        fstream Stream(s2ws(Pathb), fstream::out | ios_base::trunc);
                        Stream.close();
                        ofstream fixb(s2ws(Pathb));
                        fixb<<bal<<endl;
                        fixb.close();
                    }
                    if(views<0)
                    {
                        views=0;
                        fstream Stream(s2ws(Pathv), fstream::out | ios_base::trunc);
                        Stream.close();
                        ofstream fixv(s2ws(Pathv));
                        fixv<<sub<<endl;
                        fixv.close();
                    }
                    string subc,balc,viewc;
                    balc=to_string(bal);
                    viewc=to_string(views);
                    subc=to_string(sub);
                    send_message(event.target,MessageSegment::at(event.user_id)+"的频道信息:"+"订阅者: "+subc+" "+"存款: "+balc+" "+"观看量: "+viewc+" ");
                }
                //channel video upload
                if(event.message=="pls game upload")
                {
                    string root,userid;
                    root=dir::app();
                    userid=to_string(event.user_id);
                    string Pathi;
                    Pathi=root+userid+"_olt.ini";
                    int owned;
                    ifstream infile (s2ws(Pathi));
                    infile>>owned;
                    infile.close();
                    if(owned<0)
                    {
                        owned=0;
                        ofstream store(s2ws(Pathi));
                        store<<owned<<endl;
                        store.close();
                    }
                    if(owned==0)
                    {
                        send_message(event.target,"你还没有电脑，做不了视频，去买一个吧");
                    }
                    else if(owned==1)
                    {  
                        string Paths,Pathb,Pathv;
                        Pathv=root+userid+"_views.ini";
                        Paths=root+userid+"_subs.ini";
                        Pathb=root+userid+"_coin.ini";
                        int sub,bal,views;
                        ifstream infile (s2ws(Paths));
                        infile>>sub;
                        infile.close();
                        ifstream loadb (s2ws(Pathb));
                        loadb>>bal;
                        loadb.close();
                        ifstream loadv (s2ws(Pathv));
                        loadv>>views;
                        loadv.close();
                        if(sub<0)
                        {
                            sub=0;
                            fstream Stream(s2ws(Paths), fstream::out | ios_base::trunc);
                            Stream.close();
                            ofstream fixs(s2ws(Paths));
                            fixs<<sub<<endl;
                            fixs.close();
                        }
                        if(bal<0)
                        {
                            bal=0;
                            fstream Stream(s2ws(Pathb), fstream::out | ios_base::trunc);
                            Stream.close();
                            ofstream fixb(s2ws(Pathb));
                            fixb<<bal<<endl;
                            fixb.close();
                        }
                        if(views<0)
                        {
                            views=0;
                            fstream Stream(s2ws(Pathv), fstream::out | ios_base::trunc);
                            Stream.close();
                            ofstream fixv(s2ws(Pathv));
                            fixv<<sub<<endl;
                            fixv.close();
                        }
                        if(sub<50)
                        {
                            int token;
                            token=rand();
                            if(token%8==0)
                            {
                                send_message(event.target,"新视频获得了 8 播放。");
                                send_message(event.target,"获取了 1 粉丝。你的粉丝还不足开启激励计划。");
                                views=views+8;
                                sub=sub+1;
                                fstream Stream(s2ws(Paths), fstream::out | ios_base::trunc);
                                Stream.close();
                                ofstream outs(s2ws(Paths));
                                outs<<sub<<endl;
                                outs.close();
                                fstream VStream(s2ws(Pathv), fstream::out | ios_base::trunc);
                                VStream.close();
                                ofstream outv(s2ws(Pathv));
                                outv<<views<<endl;
                                outv.close();
                            }
                            else if(token%5==0)
                            {
                                send_message(event.target,"新视频获得了 10 播放。");
                                send_message(event.target,"获取了 2 粉丝。你的粉丝还不足开启激励计划。");
                                views=views+10;
                                sub=sub+2;
                                fstream Stream(s2ws(Paths), fstream::out | ios_base::trunc);
                                Stream.close();
                                ofstream outs(s2ws(Paths));
                                outs<<sub<<endl;
                                outs.close();
                                fstream VStream(s2ws(Pathv), fstream::out | ios_base::trunc);
                                VStream.close();
                                ofstream outv(s2ws(Pathv));
                                outv<<views<<endl;
                                outv.close();
                            }
                            else if(token%3==0)
                            {
                                send_message(event.target,"新视频获得了 12 播放。");
                                send_message(event.target,"获取了 3 粉丝。你的粉丝还不足开启激励计划。");
                                views=views+12;
                                sub=sub+3;
                                fstream Stream(s2ws(Paths), fstream::out | ios_base::trunc);
                                Stream.close();
                                ofstream outs(s2ws(Paths));
                                outs<<sub<<endl;
                                outs.close();
                                fstream VStream(s2ws(Pathv), fstream::out | ios_base::trunc);
                                VStream.close();
                                ofstream outv(s2ws(Pathv));
                                outv<<views<<endl;
                                outv.close();
                            }
                            else if(token%10==0)
                            {
                                send_message(event.target,"新视频获得了 25 播放。");
                                send_message(event.target,"获取了 5 粉丝。你的粉丝还不足开启激励计划。");
                                views=views+25;
                                sub=sub+5;
                                fstream Stream(s2ws(Paths), fstream::out | ios_base::trunc);
                                Stream.close();
                                ofstream outs(s2ws(Paths));
                                outs<<sub<<endl;
                                outs.close();
                                fstream VStream(s2ws(Pathv), fstream::out | ios_base::trunc);
                                VStream.close();
                                ofstream outv(s2ws(Pathv));
                                outv<<views<<endl;
                                outv.close();
                            }
                            else if(token%13==0)
                            {
                                send_message(event.target,"新视频获得了 28 播放。");
                                send_message(event.target,"获取了 8 粉丝。你的粉丝还不足开启激励计划。");
                                views=views+28;
                                sub=sub+28;
                                fstream Stream(s2ws(Paths), fstream::out | ios_base::trunc);
                                Stream.close();
                                ofstream outs(s2ws(Paths));
                                outs<<sub<<endl;
                                outs.close();
                                fstream VStream(s2ws(Pathv), fstream::out | ios_base::trunc);
                                VStream.close();
                                ofstream outv(s2ws(Pathv));
                                outv<<views<<endl;
                                outv.close();
                            }
                            else if(token%18==0)
                            {
                                send_message(event.target,"新视频获得了 36 播放。");
                                send_message(event.target,"获取了 6 粉丝。你的粉丝还不足开启激励计划。");
                                views=views+36;
                                sub=sub+6;
                                fstream Stream(s2ws(Paths), fstream::out | ios_base::trunc);
                                Stream.close();
                                ofstream outs(s2ws(Paths));
                                outs<<sub<<endl;
                                outs.close();
                                fstream VStream(s2ws(Pathv), fstream::out | ios_base::trunc);
                                VStream.close();
                                ofstream outv(s2ws(Pathv));
                                outv<<views<<endl;
                                outv.close();
                            }
                            else if(token%2==0)
                            {
                                send_message(event.target,"新视频获得了 4 播放。");
                                send_message(event.target,"获取了 2 粉丝。你的粉丝还不足开启激励计划。");
                                views=views+4;
                                sub=sub+2;
                                fstream Stream(s2ws(Paths), fstream::out | ios_base::trunc);
                                Stream.close();
                                ofstream outs(s2ws(Paths));
                                outs<<sub<<endl;
                                outs.close();
                                fstream VStream(s2ws(Pathv), fstream::out | ios_base::trunc);
                                VStream.close();
                                ofstream outv(s2ws(Pathv));
                                outv<<views<<endl;
                                outv.close();
                            }
                            else if(token%6==0)
                            {
                                send_message(event.target,"新视频获得了 12 播放。");
                                send_message(event.target,"获取了 3 粉丝。你的粉丝还不足开启激励计划。");
                                views=views+12;
                                sub=sub+3;
                                fstream Stream(s2ws(Paths), fstream::out | ios_base::trunc);
                                Stream.close();
                                ofstream outs(s2ws(Paths));
                                outs<<sub<<endl;
                                outs.close();
                                fstream VStream(s2ws(Pathv), fstream::out | ios_base::trunc);
                                VStream.close();
                                ofstream outv(s2ws(Pathv));
                                outv<<views<<endl;
                                outv.close();
                            }
                            else if(token%9==0)
                            {
                                send_message(event.target,"新视频获得了 18 播放。");
                                send_message(event.target,"获取了 5 粉丝。你的粉丝还不足开启激励计划。");
                                views=views+18;
                                sub=sub+5;
                                fstream Stream(s2ws(Paths), fstream::out | ios_base::trunc);
                                Stream.close();
                                ofstream outs(s2ws(Paths));
                                outs<<sub<<endl;
                                outs.close();
                                fstream VStream(s2ws(Pathv), fstream::out | ios_base::trunc);
                                VStream.close();
                                ofstream outv(s2ws(Pathv));
                                outv<<views<<endl;
                                outv.close();
                            }
                            else
                            {
                                send_message(event.target,"新视频获得了 1 播放。");
                                send_message(event.target,"获取了 0 粉丝。你的粉丝还不足开启激励计划。");
                                views=views+1;
                                sub=sub+0;
                                fstream Stream(s2ws(Paths), fstream::out | ios_base::trunc);
                                Stream.close();
                                ofstream outs(s2ws(Paths));
                                outs<<sub<<endl;
                                outs.close();
                                fstream VStream(s2ws(Pathv), fstream::out | ios_base::trunc);
                                VStream.close();
                                ofstream outv(s2ws(Pathv));
                                outv<<views<<endl;
                                outv.close();
                            }
                        }
                        else if(sub>=100)
                        {
                            int token;
                            token=rand();
                            if(token%8==0)
                            {
                                send_message(event.target,"新视频获得了 20 播放。");
                                send_message(event.target,"获取了 5 粉丝。你获得了5元。");
                                views=views+20;
                                sub=sub+5;
                                bal=bal+5;
                                fstream Stream(s2ws(Paths), fstream::out | ios_base::trunc);
                                Stream.close();
                                ofstream outs(s2ws(Paths));
                                outs<<sub<<endl;
                                outs.close();
                                fstream VStream(s2ws(Pathv), fstream::out | ios_base::trunc);
                                VStream.close();
                                ofstream outv(s2ws(Pathv));
                                outv<<views<<endl;
                                outv.close();
                                fstream BStream(s2ws(Pathb), fstream::out | ios_base::trunc);
                                BStream.close();
                                ofstream outb(s2ws(Pathb));
                                outb<<bal<<endl;
                                outb.close();
                            }
                            else if(token%5==0)
                            {
                                send_message(event.target,"新视频获得了 15 播放。");
                                send_message(event.target,"获取了 5 粉丝。你获得了5元。");
                                views=views+15;
                                sub=sub+5;
                                bal=bal+5;
                                fstream Stream(s2ws(Paths), fstream::out | ios_base::trunc);
                                Stream.close();
                                ofstream outs(s2ws(Paths));
                                outs<<sub<<endl;
                                outs.close();
                                fstream VStream(s2ws(Pathv), fstream::out | ios_base::trunc);
                                VStream.close();
                                ofstream outv(s2ws(Pathv));
                                outv<<views<<endl;
                                outv.close();
                                fstream BStream(s2ws(Pathb), fstream::out | ios_base::trunc);
                                BStream.close();
                                ofstream outb(s2ws(Pathb));
                                outb<<bal<<endl;
                                outb.close();
                            }
                            else if(token%3==0)
                            {
                                send_message(event.target,"新视频获得了 13 播放。");
                                send_message(event.target,"获取了 4 粉丝。你获得了5元。");
                                views=views+13;
                                sub=sub+4;
                                bal=bal+5;
                                fstream Stream(s2ws(Paths), fstream::out | ios_base::trunc);
                                Stream.close();
                                ofstream outs(s2ws(Paths));
                                outs<<sub<<endl;
                                outs.close();
                                fstream VStream(s2ws(Pathv), fstream::out | ios_base::trunc);
                                VStream.close();
                                ofstream outv(s2ws(Pathv));
                                outv<<views<<endl;
                                outv.close();
                                fstream BStream(s2ws(Pathb), fstream::out | ios_base::trunc);
                                BStream.close();
                                ofstream outb(s2ws(Pathb));
                                outb<<bal<<endl;
                                outb.close();
                            }
                            else if(token%10==0)
                            {
                                send_message(event.target,"新视频获得了 35 播放。");
                                send_message(event.target,"获取了 10 粉丝。你获得了8元。");
                                views=views+35;
                                sub=sub+10;
                                bal=bal+8;
                                fstream Stream(s2ws(Paths), fstream::out | ios_base::trunc);
                                Stream.close();
                                ofstream outs(s2ws(Paths));
                                outs<<sub<<endl;
                                outs.close();
                                fstream VStream(s2ws(Pathv), fstream::out | ios_base::trunc);
                                VStream.close();
                                ofstream outv(s2ws(Pathv));
                                outv<<views<<endl;
                                outv.close();
                                fstream BStream(s2ws(Pathb), fstream::out | ios_base::trunc);
                                BStream.close();
                                ofstream outb(s2ws(Pathb));
                                outb<<bal<<endl;
                                outb.close();
                            }
                            else if(token%13==0)
                            {
                                send_message(event.target,"新视频获得了 45 播放。");
                                send_message(event.target,"获取了 12 粉丝。你获得了10元。");
                                views=views+45;
                                sub=sub+12;
                                bal=bal+10;
                                fstream Stream(s2ws(Paths), fstream::out | ios_base::trunc);
                                Stream.close();
                                ofstream outs(s2ws(Paths));
                                outs<<sub<<endl;
                                outs.close();
                                fstream VStream(s2ws(Pathv), fstream::out | ios_base::trunc);
                                VStream.close();
                                ofstream outv(s2ws(Pathv));
                                outv<<views<<endl;
                                outv.close();
                                fstream BStream(s2ws(Pathb), fstream::out | ios_base::trunc);
                                BStream.close();
                                ofstream outb(s2ws(Pathb));
                                outb<<bal<<endl;
                                outb.close();
                            }
                            else if(token%18==0)
                            {
                                send_message(event.target,"新视频获得了 50 播放。");
                                send_message(event.target,"获取了 20 粉丝。你获得了18元。");
                                views=views+50;
                                sub=sub+20;
                                bal=bal+18;
                                fstream Stream(s2ws(Paths), fstream::out | ios_base::trunc);
                                Stream.close();
                                ofstream outs(s2ws(Paths));
                                outs<<sub<<endl;
                                outs.close();
                                fstream VStream(s2ws(Pathv), fstream::out | ios_base::trunc);
                                VStream.close();
                                ofstream outv(s2ws(Pathv));
                                outv<<views<<endl;
                                outv.close();
                                fstream BStream(s2ws(Pathb), fstream::out | ios_base::trunc);
                                BStream.close();
                                ofstream outb(s2ws(Pathb));
                                outb<<bal<<endl;
                                outb.close();
                            }
                            else if(token%2==0)
                            {
                                send_message(event.target,"新视频获得了 6 播放。");
                                send_message(event.target,"获取了 3 粉丝。你获得了2元。");
                                views=views+6;
                                sub=sub+3;
                                bal=bal+2;
                                fstream Stream(s2ws(Paths), fstream::out | ios_base::trunc);
                                Stream.close();
                                ofstream outs(s2ws(Paths));
                                outs<<sub<<endl;
                                outs.close();
                                fstream VStream(s2ws(Pathv), fstream::out | ios_base::trunc);
                                VStream.close();
                                ofstream outv(s2ws(Pathv));
                                outv<<views<<endl;
                                outv.close();
                                fstream BStream(s2ws(Pathb), fstream::out | ios_base::trunc);
                                BStream.close();
                                ofstream outb(s2ws(Pathb));
                                outb<<bal<<endl;
                                outb.close();
                            }
                            else if(token%6==0)
                            {
                                send_message(event.target,"新视频获得了 18 播放。");
                                send_message(event.target,"获取了 6 粉丝。你获得了4元。");
                                views=views+18;
                                sub=sub+6;
                                bal=bal+4;
                                fstream Stream(s2ws(Paths), fstream::out | ios_base::trunc);
                                Stream.close();
                                ofstream outs(s2ws(Paths));
                                outs<<sub<<endl;
                                outs.close();
                                fstream VStream(s2ws(Pathv), fstream::out | ios_base::trunc);
                                VStream.close();
                                ofstream outv(s2ws(Pathv));
                                outv<<views<<endl;
                                outv.close();
                                fstream BStream(s2ws(Pathb), fstream::out | ios_base::trunc);
                                BStream.close();
                                ofstream outb(s2ws(Pathb));
                                outb<<bal<<endl;
                                outb.close();
                            }
                            else if(token%9==0)
                            {
                                send_message(event.target,"新视频获得了 25 播放。");
                                send_message(event.target,"获取了 9 粉丝。你获得了7元。");
                                views=views+25;
                                sub=sub+9;
                                bal=bal+7;
                                fstream Stream(s2ws(Paths), fstream::out | ios_base::trunc);
                                Stream.close();
                                ofstream outs(s2ws(Paths));
                                outs<<sub<<endl;
                                outs.close();
                                fstream VStream(s2ws(Pathv), fstream::out | ios_base::trunc);
                                VStream.close();
                                ofstream outv(s2ws(Pathv));
                                outv<<views<<endl;
                                outv.close();
                                fstream BStream(s2ws(Pathb), fstream::out | ios_base::trunc);
                                BStream.close();
                                ofstream outb(s2ws(Pathb));
                                outb<<bal<<endl;
                                outb.close();
                            }
                            else
                            {
                                send_message(event.target,"新视频获得了 10 播放。");
                                send_message(event.target,"获取了 2 粉丝。你获得了1元。");
                                views=views+10;
                                sub=sub+2;
                                bal=bal+1;
                                fstream Stream(s2ws(Paths), fstream::out | ios_base::trunc);
                                Stream.close();
                                ofstream outs(s2ws(Paths));
                                outs<<sub<<endl;
                                outs.close();
                                fstream VStream(s2ws(Pathv), fstream::out | ios_base::trunc);
                                VStream.close();
                                ofstream outv(s2ws(Pathv));
                                outv<<views<<endl;
                                outv.close();
                                fstream BStream(s2ws(Pathb), fstream::out | ios_base::trunc);
                                BStream.close();
                                ofstream outb(s2ws(Pathb));
                                outb<<bal<<endl;
                                outb.close();
                            }
                        }
                        else if(sub>=50 && sub<100)
                        {
                            int token;
                            token=rand();
                            if(token%8==0)
                            {
                                send_message(event.target,"新视频获得了 12 播放。");
                                send_message(event.target,"获取了 3 粉丝。你的粉丝还不足开启激励计划。");
                                views=views+12;
                                sub=sub+3;
                                fstream Stream(s2ws(Paths), fstream::out | ios_base::trunc);
                                Stream.close();
                                ofstream outs(s2ws(Paths));
                                outs<<sub<<endl;
                                outs.close();
                                fstream VStream(s2ws(Pathv), fstream::out | ios_base::trunc);
                                VStream.close();
                                ofstream outv(s2ws(Pathv));
                                outv<<views<<endl;
                                outv.close();
                            }
                            else if(token%5==0)
                            {
                                send_message(event.target,"新视频获得了 15 播放。");
                                send_message(event.target,"获取了 5 粉丝。你的粉丝还不足开启激励计划。");
                                views=views+15;
                                sub=sub+5;
                                fstream Stream(s2ws(Paths), fstream::out | ios_base::trunc);
                                Stream.close();
                                ofstream outs(s2ws(Paths));
                                outs<<sub<<endl;
                                outs.close();
                                fstream VStream(s2ws(Pathv), fstream::out | ios_base::trunc);
                                VStream.close();
                                ofstream outv(s2ws(Pathv));
                                outv<<views<<endl;
                                outv.close();
                            }
                            else if(token%3==0)
                            {
                                send_message(event.target,"新视频获得了 13 播放。");
                                send_message(event.target,"获取了 4 粉丝。你的粉丝还不足开启激励计划。");
                                views=views+13;
                                sub=sub+4;
                                fstream Stream(s2ws(Paths), fstream::out | ios_base::trunc);
                                Stream.close();
                                ofstream outs(s2ws(Paths));
                                outs<<sub<<endl;
                                outs.close();
                                fstream VStream(s2ws(Pathv), fstream::out | ios_base::trunc);
                                VStream.close();
                                ofstream outv(s2ws(Pathv));
                                outv<<views<<endl;
                                outv.close();
                            }
                            else if(token%10==0)
                            {
                                send_message(event.target,"新视频获得了 35 播放。");
                                send_message(event.target,"获取了 10 粉丝。你的粉丝还不足开启激励计划。");
                                views=views+35;
                                sub=sub+10;
                                fstream Stream(s2ws(Paths), fstream::out | ios_base::trunc);
                                Stream.close();
                                ofstream outs(s2ws(Paths));
                                outs<<sub<<endl;
                                outs.close();
                                fstream VStream(s2ws(Pathv), fstream::out | ios_base::trunc);
                                VStream.close();
                                ofstream outv(s2ws(Pathv));
                                outv<<views<<endl;
                                outv.close();
                            }
                            else if(token%13==0)
                            {
                                send_message(event.target,"新视频获得了 45 播放。");
                                send_message(event.target,"获取了 12 粉丝。你的粉丝还不足开启激励计划。");
                                views=views+45;
                                sub=sub+12;
                                fstream Stream(s2ws(Paths), fstream::out | ios_base::trunc);
                                Stream.close();
                                ofstream outs(s2ws(Paths));
                                outs<<sub<<endl;
                                outs.close();
                                fstream VStream(s2ws(Pathv), fstream::out | ios_base::trunc);
                                VStream.close();
                                ofstream outv(s2ws(Pathv));
                                outv<<views<<endl;
                                outv.close();
                            }
                            else if(token%18==0)
                            {
                                send_message(event.target,"新视频获得了 50 播放。");
                                send_message(event.target,"获取了 20 粉丝。你的粉丝还不足开启激励计划。");
                                views=views+50;
                                sub=sub+20;
                                fstream Stream(s2ws(Paths), fstream::out | ios_base::trunc);
                                Stream.close();
                                ofstream outs(s2ws(Paths));
                                outs<<sub<<endl;
                                outs.close();
                                fstream VStream(s2ws(Pathv), fstream::out | ios_base::trunc);
                                VStream.close();
                                ofstream outv(s2ws(Pathv));
                                outv<<views<<endl;
                                outv.close();
                            }
                            else if(token%2==0)
                            {
                                send_message(event.target,"新视频获得了 6 播放。");
                                send_message(event.target,"获取了 3 粉丝。你的粉丝还不足开启激励计划。");
                                views=views+6;
                                sub=sub+3;
                                fstream Stream(s2ws(Paths), fstream::out | ios_base::trunc);
                                Stream.close();
                                ofstream outs(s2ws(Paths));
                                outs<<sub<<endl;
                                outs.close();
                                fstream VStream(s2ws(Pathv), fstream::out | ios_base::trunc);
                                VStream.close();
                                ofstream outv(s2ws(Pathv));
                                outv<<views<<endl;
                                outv.close();
                            }
                            else if(token%6==0)
                            {
                                send_message(event.target,"新视频获得了 18 播放。");
                                send_message(event.target,"获取了 6 粉丝。你的粉丝还不足开启激励计划。");
                                views=views+18;
                                sub=sub+6;
                                fstream Stream(s2ws(Paths), fstream::out | ios_base::trunc);
                                Stream.close();
                                ofstream outs(s2ws(Paths));
                                outs<<sub<<endl;
                                outs.close();
                                fstream VStream(s2ws(Pathv), fstream::out | ios_base::trunc);
                                VStream.close();
                                ofstream outv(s2ws(Pathv));
                                outv<<views<<endl;
                                outv.close();
                            }
                            else if(token%9==0)
                            {
                                send_message(event.target,"新视频获得了 25 播放。");
                                send_message(event.target,"获取了 9 粉丝。你的粉丝还不足开启激励计划。");
                                views=views+25;
                                sub=sub+9;
                                fstream Stream(s2ws(Paths), fstream::out | ios_base::trunc);
                                Stream.close();
                                ofstream outs(s2ws(Paths));
                                outs<<sub<<endl;
                                outs.close();
                                fstream VStream(s2ws(Pathv), fstream::out | ios_base::trunc);
                                VStream.close();
                                ofstream outv(s2ws(Pathv));
                                outv<<views<<endl;
                                outv.close();
                            }
                            else
                            {
                                send_message(event.target,"新视频获得了 10 播放。");
                                send_message(event.target,"获取了 2 粉丝。你的粉丝还不足开启激励计划。");
                                views=views+10;
                                sub=sub+2;
                                fstream Stream(s2ws(Paths), fstream::out | ios_base::trunc);
                                Stream.close();
                                ofstream outs(s2ws(Paths));
                                outs<<sub<<endl;
                                outs.close();
                                fstream VStream(s2ws(Pathv), fstream::out | ios_base::trunc);
                                VStream.close();
                                ofstream outv(s2ws(Pathv));
                                outv<<views<<endl;
                                outv.close();
                            }
                        }
                    }
                }
            if(event.message=="pls pictest")
            {
                send_message(event.target,MessageSegment::image("a.png"));
            }
            if(event.message=="pls giftest")
            {
                send_message(event.target,MessageSegment::image("fortnite.gif"));
            }
            if(event.message=="pls meme")
            {
                send_message(event.target,MessageSegment::at(event.user_id)+"稍等，发送图片可能有些延迟喔");
                int token;
                re:
                token=rand();
                if(token%5==0)
                {
                    send_message(event.target,MessageSegment::image("a.png")+"Credits: Windscape ");
                    //a
                }
                else if(token%6==0)
                {
                    send_message(event.target,MessageSegment::image("meme1.jpg")+"Credits: LFIO");
                    //meme1
                }
                else if(token%7==0)
                {
                    send_message(event.target,MessageSegment::image("meme2.jpg")+"Credits: Unknown");
                    //meme2
                }
                else if(token%11==0)
                {
                    send_message(event.target,MessageSegment::image("meme3.jpg")+"Credits: Unknown");
                    //meme3
                }
                else if(token%15==0)
                {
                    send_message(event.target,MessageSegment::image("yes.png")+"Credits: Fallout Game Series");
                }
                else if(token%18==0)
                {
                    send_message(event.target,MessageSegment::image("toilet.png")+"Credits: Facebook");
                }
                else if(token%21==0)
                {
                    send_message(event.target,MessageSegment::image("memerecent330.png")+"Credits: Facebook");
                }
                else if(token%23==0)
                {
                    send_message(event.target,MessageSegment::image("buyit.png")+"Credits: Unknown");
                }
                else if(token%9==0)
                {
                    send_message(event.target,MessageSegment::image("miqi.png")+"Credits: Disney");
                }
                else if(token%3==0)
                {
                    send_message(event.target,MessageSegment::image("rsheep.png")+"Credits: Twitter");
                }
                else if(token%25==0)
                {
                    send_message(event.target,MessageSegment::image("takeaway.png")+"Credits: Twitter");
                }
                else if(token%27==0)
                {
                    send_message(event.target,MessageSegment::image("pa.png")+"Credits: Unknown");
                }
                else
                {
                    goto re;
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
