local groupperson = class("groupperson")
local person = __G_REQUIRE("app.ui.battle.personai");
local vector2d = __G_REQUIRE("app.shared.vector2d");
function groupperson:ctor(parent,num,feature,pox,poy,targetx,targety)
	self.entityArray = {}
	self.enemys = {} --需要解决掉的敌人,按照顺序执行
	self.curEnemyGroup = nil; --当前面对的敌人。
	self.parent = parent;

	self.targetx = targetx;
	self.targety = targety;
	for i = 1, 4 do
		local en = person.new(self,feature,0.6);
		if i == 4 then
			en.leader = true;
		end
		local rpx = math.random(pox-100,pox);
		local rpy = math.random(poy-100,poy);
		local vpx = math.random(1,2);
		local vpy = math.random(1,2);
		en:setPosVector2d(vector2d.new(rpx,rpy));
		en.velocity = vector2d.new(vpx,vpy);
		en:setStageBounds(parent.stagewidth,parent.stageheight)
		table.insert(self.entityArray,en)
		table.insert(parent.allperson,en)
		parent.m_rootView:addChild(en);
	end

	--加载行为树
	self.tree = b3.BehaviorTree.new();
	self.blackboard = b3.Blackborad.new();
	local fileUtils = cc.FileUtils:getInstance()
    local fullpath = fileUtils:fullPathForFilename("res/ai/GroupMoveAI.json")
    local data = json.decode( io.readfile(fullpath))
    self.tree:load(data)
    print(self.tree.root)
end

function groupperson:addEnemysGroup(targetgroup,data)
	table.insert(self.enemys,targetgroup)
	self.battledata = data;
end

function groupperson:updateGroup()
	self.tree:tick(self,self.blackboard)
end

--所有的人待命
function groupperson:idle()
	for i=1,#self.entityArray, 1 do 
		local en = self.entityArray[i]
		en:idle();
	end
end

function groupperson:isAllDead()
	for i=1,#self.entityArray, 1 do 
		local en = self.entityArray[i]
		if en.isDeaded == false then
			return false
		end
	end
	return true;
end

function groupperson:enemyIsInGroupSigh()
	for i=1,#self.curEnemyGroup.entityArray,1 do
		local tg = self.curEnemyGroup.entityArray[i];
		for j=1,#self.entityArray,1 do
			local en = self.entityArray[j]
			local result = en:inSight(tg);
			if result then
				return true;
			end
		end
	end

	return false;
end



return groupperson