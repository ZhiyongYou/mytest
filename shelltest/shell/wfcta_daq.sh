#!/bin/sh

source /opt/daq/jianding/functions.sh
CFG_BASE=/opt/daq/lhaasodaq/cfg/wfcta
CFG_ALL=/opt/daq/lhaasodaq/cfg/wfcta/config_all

if [ $# -ne 3 ]; then
    echo "usage:"
    echo "  wfcta_daq.sh <telescope_id> <action> <config_file_id>"
fi

tel_id=`printf '%02d' $1`
action=$2
cfg=$3

s_env=daqenv_wfcta${tel_id}
s_stop='edaq_manager.py app-cmd -c stop'
s_state='edaq_manager.py app-state'
s_kill_app='edaq_manager.py app-kill'
s_run_app='edaq_manager.py app-run'
s_start='edaq_manager.py app-cmd -c start'
s_restart_service='edaq_quick_restart.sh'

function change_config
{
    cfg_dir=${CFG_ALL}/w${tel_id}/${cfg}
    target_cfg_dir=${CFG_BASE}/wfcta${tel_id}

    rm ${target_cfg_dir}
    ln -s ${cfg_dir} ${target_cfg_dir}
}

function restart_daq
{
    ${s_env}
    ${s_stop}
    sleep 1
    ${s_kill_app}
    sleep 1
    ${s_restart_service}
    sleep 1
    ${s_run_app}
    sleep 5
    ${s_start}
}

function state_daq
{
    ${s_env}
    ${s_state}
}

function stop_daq
{
    ${s_env}
    ${s_stop}
    sleep 1
    ${s_kill_app}
}

function rate_daq
{
    ${s_env}
    dump_redis.py -r 'df.*CH.*hit_count.rate' |grep hit_count.rate
}

function output_rate_daq
{
    ${s_env}
    dump_redis.py -r 'df.*saved_event_volume.rate'
}

change_config $tel_id $cfg

if [ "$action" == "start" ]; then
    restart_daq $tel_id
elif [ "$action" == "stop" ]; then
    stop_daq
elif [ "$action" == "state" ]; then
    state_daq
elif [ "$action" == "rate" ]; then
    rate_daq
elif [ "$action" == "output_rate" ]; then
    output_rate_daq
fi

