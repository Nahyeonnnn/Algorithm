SELECT user_id, nickname, 
concat(u.city, ' ', u.STREET_ADDRESS1, ' ', u.STREET_ADDRESS2) as '전체주소'
, concat(substr(TLNO, 1, 3), '-', substr(TLNO, 4, 4), '-', substr(TLNO, 8, 4)) as '전화번호'
from USED_GOODS_USER u join USED_GOODS_BOARD b on b.WRITER_ID = u.USER_ID
group by writer_id 
having count(writer_id) > 2
order by user_id desc