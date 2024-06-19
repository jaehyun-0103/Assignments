package org.tukorea.club.test;

import org.junit.Test;
import org.junit.runner.RunWith;
import org.tukorea.club.domain.ClubVO;
import org.tukorea.club.persistence.ClubDAO;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.test.context.ContextConfiguration;
import org.springframework.test.context.junit4.SpringJUnit4ClassRunner;
import org.springframework.transaction.annotation.Transactional;

@RunWith(SpringJUnit4ClassRunner.class)
@ContextConfiguration(locations = { "file:src/main/webapp/WEB-INF/spring/root-context.xml" })
@Transactional
public class ClubDAOTest {
	
	@Autowired
	private ClubDAO clubDAO;
	
	@Test
	public void testAdd() throws Exception {
		ClubVO vo = new ClubVO();
		vo.setClubName("이름");
		vo.setDescription("설명");
		vo.setCategory("카테고리");
		vo.setCapacity(3);
		vo.setLocation("지역");
		vo.setMeetingDate("주기");
		vo.setVenue("장소");
		clubDAO.add(vo);
	}
	
	@Test
	public void testDelete() throws Exception {
		clubDAO.delete(1);
	}
}
