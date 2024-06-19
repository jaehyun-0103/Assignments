package org.tukorea.di.main;

import java.util.InputMismatchException;
import java.util.List;
import java.util.Scanner;

import org.tukorea.di.domain.StudentVO;
import org.tukorea.di.service.MemberService;
import org.springframework.context.ApplicationContext;
import org.springframework.context.support.GenericXmlApplicationContext;
import org.springframework.dao.DuplicateKeyException;

public class MemberSampleMain {

	private static ApplicationContext ctx = null;

	public static void main(String[] args) throws Exception {
		ctx = new GenericXmlApplicationContext("applicationContext.xml");

		MemberService memberService = ctx.getBean(MemberService.class);

		Scanner scan = new Scanner(System.in);

		while (true)

		{
			System.out.println("----------------------------------");
			System.out.println("\t학생 정보 관리 프로그램");
			System.out.println("----------------------------------");
			System.out.println("1. 전체 학생 정보 출력");
			System.out.println("2. 개인 학생 정보 출력");
			System.out.println("3. 개인 학생 정보 생성");
			System.out.println("4. 개인 학생 정보 삭제");
			System.out.println("5. 개인 학생 정보 수정");
			System.out.println("6. 프로그램 종료");
			System.out.println("----------------------------------");

			System.out.print("번호 선택 : ");
			try {
				int sel = scan.nextInt();
				scan.nextLine();
				switch (sel) {
				case 1: // 전체 학생 정보 출력
					List<StudentVO> list = memberService.readMemberList();
					for (StudentVO svo : list) {
						System.out.println("----------------------------------");
						System.out.println(" id : " + svo.getId());
						System.out.println(" passwd : " + svo.getPasswd());
						System.out.println(" username : " + svo.getUsername());
						System.out.println(" snum : " + svo.getSnum());
						System.out.println(" depart : " + svo.getDepart());
						System.out.println(" mobile : " + svo.getMobile());
						System.out.println(" email : " + svo.getEmail());
					}
					break;
				case 2: // 개인 학생 정보 출력
					System.out.print("출력할 학생의 id : ");

					try {
						String uid = scan.nextLine();
						StudentVO member = memberService.readMember(uid);
						System.out.println("----------------------------------");
						System.out.println(" id : " + member.getId());
						System.out.println(" passwd : " + member.getPasswd());
						System.out.println(" username : " + member.getUsername());
						System.out.println(" snum : " + member.getSnum());
						System.out.println(" depart : " + member.getDepart());
						System.out.println(" mobile : " + member.getMobile());
						System.out.println(" email : " + member.getEmail());
					} catch (NullPointerException e) {
						System.out.println("Error: 학생 id가 존재하지 않습니다.");
					}
					break;
				case 3: // 개인 학생 정보 생성
					System.out.print("생성할 학생의 id : ");
					String addId = scan.nextLine();

					if (memberService.readMember(addId) != null) {
						System.out.println("----------------------------------");
						System.out.println("Error: 학생 id가 이미 존재합니다.");
						break;
					}

					System.out.print("passwd : ");
					String addPasswd = scan.nextLine();
					System.out.print("username : ");
					String addUsername = scan.nextLine();
					System.out.print("snum : ");
					String addSnum = scan.nextLine();
					System.out.print("depart : ");
					String addDepart = scan.nextLine();
					System.out.print("mobile : ");
					String addMobile = scan.nextLine();
					System.out.print("email : ");
					String addEmail = scan.nextLine();

					try {
						StudentVO vo = new StudentVO();
						vo.setId(addId);
						vo.setPasswd(addPasswd);
						vo.setUsername(addUsername);
						vo.setSnum(addSnum);
						vo.setDepart(addDepart);
						vo.setMobile(addMobile);
						vo.setEmail(addEmail);
						memberService.addMember(vo);
					} catch (DuplicateKeyException e) {
						System.out.println("----------------------------------");
						System.out.println("Error: 학생 id가 이미 존재합니다.");
						continue;
					}
					System.out.println("----------------------------------");
					System.out.println("Success: 학생 정보가 성공적으로 추가되었습니다.");
					break;
				case 4: // 개인 학생 정보 삭제
					try {
						System.out.print("삭제할 학생의 id : ");
						String deleteId = scan.nextLine();
						memberService.deleteMember(deleteId);
					} catch (Exception e) {
						System.out.println("----------------------------------");
						System.out.println("Error: 학생 id가 존재하지 않습니다.");
						continue;
					}
					System.out.println("----------------------------------");
					System.out.println("Success: 학생 정보가 성공적으로 삭제되었습니다.");
					break;
				case 5: // 개인 학생 정보 수정
					System.out.print("수정할 학생의 id : ");
					String updateId = scan.nextLine();
					try {
						StudentVO member = memberService.readMember(updateId);
						member.getId();
					} catch (NullPointerException e) {
						System.out.println("----------------------------------");
						System.out.println("Error: 학생 id가 존재하지 않습니다.");
						continue;
					}

					System.out.print("passwd : ");
					String updatePasswd = scan.nextLine();
					System.out.print("username : ");
					String updateUsername = scan.nextLine();
					System.out.print("snum : ");
					String updateSnum = scan.nextLine();
					System.out.print("depart : ");
					String updateDepart = scan.nextLine();
					System.out.print("mobile : ");
					String updateMobile = scan.nextLine();
					System.out.print("email : ");
					String updateEmail = scan.nextLine();

					StudentVO vo = new StudentVO();
					vo.setId(updateId);
					vo.setPasswd(updatePasswd);
					vo.setUsername(updateUsername);
					vo.setSnum(updateSnum);
					vo.setDepart(updateDepart);
					vo.setMobile(updateMobile);
					vo.setEmail(updateEmail);
					memberService.updateMember(vo);

					System.out.println("----------------------------------");
					System.out.println("Success: 학생 정보가 성공적으로 수정되었습니다.");

					break;
				case 6: // 프로그램 종료
					System.out.println("안녕히 가세요.");
					System.exit(0);
				default:
					System.out.println("----------------------------------");
					System.out.println("Error: 확인 후 입력하세요.");
				}
			} catch (InputMismatchException e) {
				scan.nextLine();
				System.out.println("----------------------------------");
				System.out.println("Error: 확인 후 입력하세요.");
				continue;
			}
		}
	}
}
