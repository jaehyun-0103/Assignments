package org.tukorea.club.persistence;

import java.util.List;
import java.util.Map;

import org.apache.ibatis.session.SqlSession;
import org.tukorea.club.domain.ClubVO;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Repository;

@Repository
public class ClubDAOImpl implements ClubDAO {

	@Autowired
	private SqlSession sqlSession;

	private static final String namespace = "ClubMapper";

	public List<ClubVO> list() throws Exception {
		return sqlSession.selectList(namespace + ".selectAllClubs");
	}

	public void add(ClubVO vo) throws Exception {
		sqlSession.insert(namespace + ".insertClub", vo);
	}

	public List<Map<String, Object>> content(int id) throws Exception {
		return sqlSession.selectList(namespace + ".selectContent", id);
	}

	public void delete(int id) throws Exception {
		sqlSession.delete(namespace + ".deleteClub", id);
	}
}
