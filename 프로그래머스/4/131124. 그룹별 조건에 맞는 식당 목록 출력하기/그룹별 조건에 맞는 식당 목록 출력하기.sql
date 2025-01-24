SELECT m.MEMBER_NAME, r.REVIEW_TEXT, date_format(r.REVIEW_DATE, '%Y-%m-%d')
from REST_REVIEW r join MEMBER_PROFILE m on m.member_id = r.member_id
where m.MEMBER_ID = (
    select m.MEMBER_ID
    from MEMBER_PROFILE m join REST_REVIEW r on m.member_id = r.member_id
    group by MEMBER_ID
    order by count(*) desc limit 1
)
order by r.REVIEW_DATE, r.REVIEW_TEXT


