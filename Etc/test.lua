selfx = Self.get(selfPtr)
selfx:pushArray(30030) 
selfx:pushArray(30020) 
selfx:pushArray(30000) 
selfx:pushArray(30480) 
selfx:pushArray(30310) 
selfx:pushArray(30330) 
selfx:pushArray(30060) 
selfx:pushArray(30150) 
selfx:pushArray(30410) 
selfx:pushArray(30210) 
selfx:pushArray(30140) 
selfx:pushArray(30120) 
selfx:pushArray(30200) 
selfx:askAvatar("Select : ", 4031249)

s = selfx:askMenu("#L0#Test0#l\r\n#L1#Test1#l\r\n#L2#Test2#l\r\n#L3#Test3#l")
s = selfx:sayNext("��ܤF�ﶵ:" .. s, 0, 0)

s = selfx:askYesNo("���� Yes No")
if(s == 1) then
    selfx:say("Press Yes")
else
    selfx:say("Press No")
end

s = selfx:askText("��J�Y�Ǥ�r:", "��r", 0, 5)
selfx:sayNext("��J����r : " .. s, 0, 0)

s = selfx:askNumber("��J�Y�Ǽƭ�:", 100, 0, 10000)
selfx:sayNext("��J���ƭ� : " .. s, 0, 0)

local page = 0
while true do
    print("Run Script , page : "..page)
    if(page == 0) then
        page = selfx:sayNext("#r�� 1 ��#k", 0, 1)  
    elseif(page == 1) then
        page = selfx:sayNext("#b�� 2 ��#k", 1, 2)  
    elseif(page == 2) then
        page = selfx:sayNext("#g�� 3 ��", 2, 3)  
    elseif(page == 3) then
        page = selfx:sayNext("�� 4 ��", 3, 4)  
    elseif(page == 4) then
        page = selfx:sayNext("�� 5 ��", 4, 5)  
    elseif(page >= 5) then break 
    else break end
end

s = selfx:sayNext("����", 0, 0)