select 
dev.ID, dev.email, dev.first_name, dev.last_name
from DEVELOPERS dev left join SKILLCODES skill
on 
length(BIN(dev.SKILL_CODE)) >= length(BIN(skill.CODE)) 
and  
substr(BIN(dev.SKILL_CODE), length(BIN(dev.SKILL_CODE)) - length(BIN(skill.CODE)) + 1, 1) = 1
where skill.category = 'Front End'
group by dev.ID, dev.email, dev.first_name, dev.last_name
order by dev.ID asc
# 10100
# 100000 skill

# select bin(code) from skillcodes;

# select bin(skill_code), first_name from developers;